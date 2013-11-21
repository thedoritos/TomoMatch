//
//  HSAssets.cpp
//  TomoMatch
//
//  Created by thedoritos on 2013/11/14.
//
//

#include "HSAssets.h"

const char* HSAssets::Get(const char* key)
{
    // Static pointer will be initialized once.
    static Json *assets = NULL;
    
    // Create if the Json is not prepared.
    if (assets == NULL) {
        
        // Get path to the file.
        const char* fileName = "assets.json";
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
