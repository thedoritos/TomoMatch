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

const int HSPlayFooter::TAG_DIALOG = 1001;
const int HSPlayFooter::TAG_BADGE_GOLD = 2001;
const int HSPlayFooter::TAG_BADGE_SILV = 2002;
const int HSPlayFooter::TAG_BADGE_BRNZ = 2003;

bool HSPlayFooter::init()
{
    if (!CCNodeRGBA::init()) return false;
    
    CCSize visSize = CCDirector::sharedDirector()->getVisibleSize();
    this->setContentSize(CCSizeMake(visSize.width, visSize.height - HSPlayHeader::kHeight));
    this->setCascadeOpacityEnabled(true);
    
    CCSize size = this->getContentSize();
    CCSize grid = CCSizeMake(visSize.width / 3.0f, visSize.width / 3.0f);
    
    // Setup background.
    CCSprite *bg = HS_CREATE_SPRITE(HS_RES_IMG("white"));
    bg->setScaleX(this->getContentSize().width / bg->getContentSize().width);
    bg->setScaleY(this->getContentSize().height / bg->getContentSize().height);
    bg->setColor(ccc3(0, 0, 0));
    bg->setOpacity(96);
    bg->setAnchorPoint(CCPointZero);
    bg->setPosition(CCPointZero);
    this->addChild(bg);
    
    // Setup badges.
    float badgeScale = 0.8f;
    float badgeTrans = 5.0f;
    
    CCSprite *gold = HS_CREATE_SPRITE(HS_RES_IMG("badge_gold"));
    gold->setPosition(ccp(grid.width * 2.5f + badgeTrans * (-1.0f),
                          size.height - grid.height * 0.5f - badgeTrans * 2.0f));
    gold->setScale(badgeScale);
    gold->setTag(TAG_BADGE_GOLD);
    this->addChild(gold);
    
    CCSprite *silv = HS_CREATE_SPRITE(HS_RES_IMG("badge_silver"));
    silv->setPosition(ccp(grid.width * 1.5f + badgeTrans * (0.0f),
                          size.height - grid.height * 0.5f - badgeTrans * 2.0f));
    silv->setScale(badgeScale);
    silv->setTag(TAG_BADGE_SILV);
    this->addChild(silv);
    
    CCSprite *brnz = HS_CREATE_SPRITE(HS_RES_IMG("badge_bronze"));
    brnz->setPosition(ccp(grid.width * 0.5f + badgeTrans * (1.0f),
                          size.height - grid.height * 0.5f - badgeTrans * 2.0f));
    brnz->setScale(badgeScale);
    brnz->setTag(TAG_BADGE_BRNZ);
    this->addChild(brnz);
    
    // Setup dialog.
    CCSprite *dialog = HS_CREATE_SPRITE(HS_RES_IMG("dialog_frame"));
    dialog->setAnchorPoint(ccp(0.5, 0.5));
    dialog->setPosition(ccp(size.width * 0.5f, size.height - grid.height * 2.0f));
    dialog->setOpacity(96);
    dialog->setTag(TAG_DIALOG);
    this->addChild(dialog);
    
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
