//
//  HSTitleLayer.h
//  TomoMatch
//
//  Created by thedoritos on 2013/11/14.
//
//

#ifndef __TomoMatch__HSTitleLayer__
#define __TomoMatch__HSTitleLayer__

#include "cocos2d.h"

using namespace cocos2d;

class HSTitleLayer : public CCLayer {
    
    CCNode *m_bgNode;
    
public:
    
    virtual bool init();
    CREATE_FUNC(HSTitleLayer);
    static CCScene* scene();
    
#pragma mark - Initialize
    virtual void onEnterTransitionDidFinish();
    
#pragma mark - Update
    virtual void update(float dt);
    
#pragma mark - Touch event handlers
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);

#pragma mark - Menu button actions
    void startGame();
    void exitGame();
};
#endif /* defined(__TomoMatch__HSTitleLayer__) */
