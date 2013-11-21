//
//  HSPlayFooter.cpp
//  TomoMatch
//
//  Created by thedoritos on 2013/11/14.
//
//

#include "HSPlayFooter.h"
#include "HSAssets.h"

#include "HSPlayHeader.h"

bool HSPlayFooter::init()
{
    if (!CCNodeRGBA::init()) return false;
    
    CCSize visSize = CCDirector::sharedDirector()->getVisibleSize();
    this->setContentSize(CCSizeMake(visSize.width, visSize.height - HSPlayHeader::kHeight));
    this->setCascadeOpacityEnabled(true);
    
    // Setup background.
    CCSprite *bg = HS_CREATE_SPRITE(HS_RES_IMG("white"));
    bg->setScaleX(this->getContentSize().width / bg->getContentSize().width);
    bg->setScaleY(this->getContentSize().height / bg->getContentSize().height);
    bg->setColor(ccc3(0, 0, 0));
    bg->setOpacity(96);
    bg->setAnchorPoint(CCPointZero);
    bg->setPosition(CCPointZero);
    this->addChild(bg);
    
    return true;
}

void HSPlayFooter::setNumBadges(int num)
{
    
}
void HSPlayFooter::setMessage(const string &message)
{
    
}
void HSPlayFooter::setTweetEnabled(bool enabled)
{
    
}
void HSPlayFooter::setContinueEnabled(bool enabled)
{
    
}
void HSPlayFooter::setQuitEnabled(bool enabled)
{
    
}

void HSPlayFooter::show(float duration)
{
    if (!this->isVisible()) {
        
        unsigned int tag = 1000;
        this->getActionManager()->removeActionByTag(tag, this);
        
        this->setAnchorPoint(ccp(0, 1));
        this->setPosition(CCPointZero);
        this->setOpacity(0);
        this->setVisible(true);
        
        CCAction *slideIn = CCSpawn::createWithTwoActions(
            CCEaseExponentialOut::create(CCMoveBy::create(duration, ccp(0, this->getContentSize().height))),
            CCEaseExponentialOut::create(CCFadeTo::create(duration, 255))
        );
        
        slideIn->setTag(tag);
        this->runAction(slideIn);
    }
}
void HSPlayFooter::dispose(float duration)
{
    if (this->isVisible()) {
        this->setVisible(false);
    }
}
