//
//  HSAssets.cpp
//  TomoMatch
//
//  Created by thedoritos on 2013/11/14.
//
//

#include "HSAssets.h"

const string HSAssets::kHSAssetList     = "assets.json";
const string HSAssets::kHSAssetCacheDir = "cache";

HSAssets* HSAssets::sharedInstance()
{
    static HSAssets instance;
    return &instance;
}

const char* HSAssets::Get(const char* key)
{
    // Static pointer will be initialized once.
    static Json *assets = NULL;
    
    // Create if the Json is not prepared.
    if (assets == NULL) {
        
        // Get path to the file.
        const char* fileName = kHSAssetList.c_str();
        std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(fileName);
        
        // @see fopen in stdio.h
        const char* openMode = "r";
        
        // File size (will be set when open the file).
        unsigned long fileSize = 0;
        
        // Get data.
        unsigned char* fileData = CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str(), openMode, &fileSize);
        
        // Create json parsing the data.
        assets = Json_create((char*) fileData);
        
        // Dispose data.
        delete fileData;
    }
    
    // Get value.
    const char* value = Json_getString(assets, key, "undefined");
    
    // Dispose Json.
//    Json_dispose(json);
    
    // Return value.
    return value;
}

string HSAssets::getPathFromKey(const char *key)
{
    stringstream ss;
    ss << CCFileUtils::sharedFileUtils()->getWritablePath();
//    ss << kHSAssetCacheDir << "/";
    ss << key << ".png";
    
    return ss.str();
}

void HSAssets::beginLoading(const char* key, const char* remotePath)
{
    // Check cached assets.
    string path = this->getPathFromKey(key);
    if (CCFileUtils::sharedFileUtils()->isFileExist(path)) {
        mSavedAssets.insert(pair<string, string>(key, path));
        if (mDelegate) {
            mDelegate->onLoadingAssetCompleted(this, key, path.c_str());
        }
        return;
    }
    
//    // Check cached assets.
//    map<string, string>::const_iterator iter = mSavedAssets.find(key);
//    if (iter != mSavedAssets.end()) {
//        if (mDelegate) {
//            mDelegate->onLoadingAssetCompleted(this, key, iter->second.c_str());
//        }
//        return;
//    }
    
    // Send Http request.
    CCHttpRequest *request = new CCHttpRequest();
    request->setUrl(remotePath);
    request->setRequestType(CCHttpRequest::kHttpGet);
    request->setResponseCallback(this, httpresponse_selector(HSAssets::onHttpRequestCompleted));
    request->setTag(key);
    CCHttpClient::getInstance()->send(request);
}

void HSAssets::onHttpRequestCompleted(CCHttpClient* client, CCHttpResponse *response)
{
    string key = response->getHttpRequest()->getTag();
    
    // Check response.
    int status = response->getResponseCode();
    if (status < 200 || status >= 300) {
        if (mDelegate) {
            mDelegate->onLoadingAssetFailed(this, key.c_str());
        }
        return;
    }
    
    // Check cached assets.
    map<string, string>::const_iterator iter = mSavedAssets.find(key);
    if (iter != mSavedAssets.end()) {
        if (mDelegate) {
            mDelegate->onLoadingAssetCompleted(this, key.c_str(), iter->second.c_str());
        }
    } else {
        // Create image.
        vector<char> *data = response->getResponseData();
        CCImage *image = new CCImage();
        image->autorelease();
        image->initWithImageData(&(data->front()), data->size());
        
        // Cache image.
        string path = this->getPathFromKey(key.c_str());
        bool saved = image->saveToFile(path.c_str());
        if (saved) {
            mSavedAssets.insert(pair<string, string>(key, path));
        }
        
        if (mDelegate) {
            mDelegate->onLoadingAssetCompleted(this, key.c_str(), path.c_str());
        }
    }
}

void HSAssets::setDelegate(HSAssetsDelegate *delegate)
{
    mDelegate = delegate;
}
