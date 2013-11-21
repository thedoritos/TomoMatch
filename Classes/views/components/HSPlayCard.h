//
//  HSPlayCard.h
//  TomoMatch
//
//  Created by thedoritos on 2013/11/14.
//
//

#ifndef __TomoMatch__HSPlayCard__
#define __TomoMatch__HSPlayCard__

#include "cocos2d.h"

using namespace cocos2d;
using namespace std;

class HSPlayCard : public CCNodeRGBA {
    
    bool m_isCompleted = false;
    
public:
    
    virtual bool init();
    CREATE_FUNC(HSPlayCard);
    
    void setCompleted(bool completed);
    
    void showHead(float duration, int numExtraTurns = 0);
    void showTail(float duration, int numExtraTurns = 0);
    
};

#endif /* defined(__TomoMatch__HSPlayCard__) */
