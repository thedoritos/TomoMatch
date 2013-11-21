//
//  HSLoadLayer.h
//  TomoMatch
//
//  Created by thedoritos on 2013/11/14.
//
//

#ifndef __TomoMatch__HSLoadLayer__
#define __TomoMatch__HSLoadLayer__

#include "cocos2d.h"
#include "HSStageModel.h"

using namespace cocos2d;
using namespace std;

class HSLoadLayer : public CCLayer {
    
    CCString m_stageTitle;
    CCString m_stageSubTitle;
    
public:
    
    virtual bool init();
    CREATE_FUNC(HSLoadLayer);
    
    void setStageModel(const HSStageModel *stageModel);
    
};
#endif /* defined(__TomoMatch__HSLoadLayer__) */
