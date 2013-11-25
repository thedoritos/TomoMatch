//
//  HSAssets.h
//  TomoMatch
//
//  Created by thedoritos on 2013/11/14.
//
//

#ifndef __TomoMatch__HSAssets__
#define __TomoMatch__HSAssets__

#include <map>
#include "cocos2d.h"
#include "spine/Json.h"
#include "HttpClient.h"
#include "HttpRequest.h"
#include "HttpResponse.h"

using namespace std;
using namespace cocos2d;
using namespace cocos2d::extension;

#define HS_RES_IMG(__key__) \
HSAssets::Get(__key__)

#define HS_CREATE_SPRITE(__fileName__)\
CCSprite::createWithTexture(CCTextureCache::sharedTextureCache()->addImage(__fileName__))

class HSAssets;
class HSAssetsDelegate;
typedef void (HSAssets::*SEL_AssetLoad)(HSAssets *loader, bool succeeded, const char* key, const char* path);
#define assetload_selector(_SELECTOR)(SEL_AssetLoad)(&_SELECTOR)

class HSAssets : CCObject {
    
public:
    
    static const string kHSAssetList;
    static const string kHSAssetCacheDir;
    
    static HSAssets* sharedInstance();
    static const char* Get(const char* key);
    
    /**
     * Begins loading images from the Web.
     * If there is a cached image found by the key, it will be loaded.
     * The methods on HSAssetDelegate is called as a result.
     *
     * @param key           The key for the cached image.
     * @param remotePath    The path(URL) of the image.
     */
    void beginLoading(const char* key, const char* remotePath);
    
    void setDelegate(HSAssetsDelegate *delegate);
    
private:
    
    HSAssets(){}
    HSAssets(const HSAssets &rhs);
    HSAssets & operator= (const HSAssets &rhs);
    
    HSAssetsDelegate *mDelegate;
    
    map<string, string> mSavedAssets;
    string getPathFromKey(const char *key);
    
    void onHttpRequestCompleted(CCHttpClient* client, CCHttpResponse *response);
};

class HSAssetsDelegate {
public:
    virtual void onLoadingAssetCompleted(HSAssets *loader, const char* key, const char* path) = 0;
    virtual void onLoadingAssetFailed(HSAssets *loader, const char* key) = 0;
};

#endif /* defined(__TomoMatch__HSAssets__) */
