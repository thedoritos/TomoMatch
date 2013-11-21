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

using namespace cocos2d;

class HSPlayLayer : public CCLayer, HSGameDelegate {
    
    HSBackground *m_background;
    HSPlayHeader *m_header;
    HSPlayFooter *m_footer;
    
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
    virtual void onLoadingCardsCompleted(HSGame *game);
    virtual void onLoadingCardsFailed(HSGame *game);
};

#endif /* defined(__TomoMatch__HSPlayLayer__) */
