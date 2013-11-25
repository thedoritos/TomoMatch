//
//  HSPlayFooter.h
//  TomoMatch
//
//  Created by thedoritos on 2013/11/14.
//
//

#ifndef __TomoMatch__HSPlayFooter__
#define __TomoMatch__HSPlayFooter__

#include "cocos2d.h"

using namespace cocos2d;
using namespace std;

class HSPlayFooter : public CCNodeRGBA {
    
    CCLabelTTF *m_messageLabel;
    
    static const int TAG_DIALOG;
    static const int TAG_BADGE_GOLD;
    static const int TAG_BADGE_SILV;
    static const int TAG_BADGE_BRNZ;
    
public:
    
    virtual bool init();
    CREATE_FUNC(HSPlayFooter);
    
    void setNumBadges(int num);
    void setMessage(const string &message);
    void setTweetEnabled(bool enabled);
    void setContinueEnabled(bool enabled);
    void setQuitEnabled(bool enabled);
    
    void show(float duration);
    void dispose(float duration);
    
};

#endif /* defined(__TomoMatch__HSPlayFooter__) */
