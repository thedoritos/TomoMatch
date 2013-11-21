//
//  HSBackground.h
//  TomoMatch
//
//  Created by thedoritos on 2013/11/14.
//
//

#ifndef __TomoMatch__HSBackground__
#define __TomoMatch__HSBackground__

#include "cocos2d.h"

using namespace cocos2d;

class HSBackground : public CCLayerColor {
    
    CCLabelTTF *m_label;
    float m_slideRate;
    
public:
    
    virtual bool init();
    CREATE_FUNC(HSBackground);
    
    virtual void update(float dt);
    virtual void draw();
    
    void setLabel(const std::string &label);
    
};

#endif /* defined(__TomoMatch__HSBackground__) */
