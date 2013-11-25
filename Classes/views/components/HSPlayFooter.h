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
    static const int TAG_DIALOG_TEXT;
    static const int TAG_BADGE_GOLD;
    static const int TAG_BADGE_SILV;
    static const int TAG_BADGE_BRNZ;
    
    static const int TAG_MENU_TWEET;
    static const int TAG_MENU_CONTINUE;
    static const int TAG_MENU_QUIT;
    
    
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
    
#pragma mark - Touch event handlers
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);

private:
    
    void menuButtonFired(CCObject *sender);
    
};

#endif /* defined(__TomoMatch__HSPlayFooter__) */
