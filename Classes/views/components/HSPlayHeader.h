//
//  HSPlayHeader.h
//  TomoMatch
//
//  Created by thedoritos on 2013/11/14.
//
//

#ifndef __TomoMatch__HSPlayHeader__
#define __TomoMatch__HSPlayHeader__

#include "cocos2d.h"

using namespace cocos2d;

class HSPlayHeader : public CCNodeRGBA {
    
    CCLabelTTF *m_timeLabel;
    CCLabelTTF *m_lifeLabel;
    CCLabelTTF *m_comboLabel;
    
public:
    
    static const float kHeight;
    
    virtual bool init();
    CREATE_FUNC(HSPlayHeader);
    
    void setTime(float second);
    void setLife(int life);
    void setCombo(int combo);
    
};

#endif /* defined(__TomoMatch__HSPlayHeader__) */
