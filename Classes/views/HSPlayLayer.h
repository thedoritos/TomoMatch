//
//  HSPlayLayer.h
//  TomoMatch
//
//  Created by thedoritos on 2013/11/14.
//
//

#ifndef __TomoMatch__HSPlayLayer__
#define __TomoMatch__HSPlayLayer__

#include "cocos2d.h"
#include "HSGame.h"
#include "HSBackground.h"
#include "HSPlayHeader.h"
#include "HSPlayFooter.h"
#include "HSPlayBoard.h"

using namespace cocos2d;

class HSPlayLayer : public CCLayer, HSGameDelegate, HSPlayFooterDelegate {
    
    HSBackground *m_background;
    HSPlayHeader *m_header;
    HSPlayFooter *m_footer;
    HSPlayBoard  *m_board;
    
public:
    
    virtual bool init();
    CREATE_FUNC(HSPlayLayer);
    static CCScene* scene();
    
#pragma mark - Update
    virtual void update(float dt);
    
#pragma mark - Touch event handlers
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);

#pragma mark - HSGameDelegate
    virtual void onLoadingTitleCompleted(HSGame *game){}
    virtual void onLoadingtitleFailed(HSGame *game){}
    virtual void onLoadingStageCompleted(HSGame *game);
    virtual void onLoadingStageFailed(HSGame *game);
    
#pragma mark - HSPlayFooterDelegate
    virtual void onTweetButtonFired(HSPlayFooter *footer);
    virtual void onContinueButtonFired(HSPlayFooter *fotter);
    virtual void onQuitButtonFired(HSPlayFooter *fotter);

};

#endif /* defined(__TomoMatch__HSPlayLayer__) */
