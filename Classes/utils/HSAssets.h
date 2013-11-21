//
//  HSAssets.h
//  TomoMatch
//
//  Created by thedoritos on 2013/11/14.
//
//

#ifndef __TomoMatch__HSAssets__
#define __TomoMatch__HSAssets__

#include "cocos2d.h"
#include "spine/Json.h"

using namespace cocos2d;
using namespace cocos2d::extension;

#define HS_RES_IMG(__key__) \
HSAssets::Get(__key__)

#define HS_CREATE_SPRITE(__fileName__)\
CCSprite::createWithTexture(CCTextureCache::sharedTextureCache()->addImage(__fileName__))

class HSAssets {
    
public:
    
    static const char* Get(const char* key);
    
};
#endif /* defined(__TomoMatch__HSAssets__) */
