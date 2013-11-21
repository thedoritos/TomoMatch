//
//  HSStageModel.h
//  TomoMatch
//
//  Created by thedoritos on 2013/11/14.
//
//

#ifndef __TomoMatch__HSStageModel__
#define __TomoMatch__HSStageModel__

#include "cocos2d.h"

using namespace cocos2d;

class HSStageModel {
    
    CCString m_title;
    CCString m_subTitle;
    
public:
    
    const CCString & getTitle() const;
    const CCString & getSubTitle() const;
    
};

#endif /* defined(__TomoMatch__HSStageModel__) */
