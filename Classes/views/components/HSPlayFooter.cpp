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

const int HSPlayFooter::TAG_DIALOG        = 1001;
const int HSPlayFooter::TAG_DIALOG_TEXT   = 1002;
const int HSPlayFooter::TAG_BADGE_GOLD    = 2001;
const int HSPlayFooter::TAG_BADGE_SILV    = 2002;
const int HSPlayFooter::TAG_BADGE_BRNZ    = 2003;
const int HSPlayFooter::TAG_MENU_TWEET    = 3001;
const int HSPlayFooter::TAG_MENU_CONTINUE = 3002;
const int HSPlayFooter::TAG_MENU_QUIT     = 3003;

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
    dialog->setOpacity(192);
    dialog->setTag(TAG_DIALOG);
    this->addChild(dialog);
    
    CCLabelTTF *text = CCLabelTTF::create("This is default text.", "Helvetica", 48.0f,
                                          CCSizeMake(dialog->getContentSize().width  * 0.90f,
                                                     dialog->getContentSize().height * 0.90f),
                                          kCCTextAlignmentLeft,
                                          kCCVerticalTextAlignmentTop);
    text->setTag(TAG_DIALOG_TEXT);
    text->setAnchorPoint(ccp(0.5, 0.5));
    text->setPosition(ccp(dialog->getContentSize().width  * 0.5f,
                          dialog->getContentSize().height * 0.5f));
    dialog->addChild(text);
    
    // Setup buttons.
    float menuScale = 0.8f;
    float menuTrans = 10.0f;
    
    CCMenuItem *btnTweet = CCMenuItemImage::create(HS_RES_IMG("footer_tweet"), HS_RES_IMG("footer_tweet_h"));
    {
        btnTweet->setTag(TAG_MENU_TWEET);
        btnTweet->setTarget(this, menu_selector(HSPlayFooter::menuButtonFired));
        btnTweet->setPosition(ccp(grid.width * -1.0f, 0));
        btnTweet->setScale(menuScale);
        CCLabelTTF *lblTweet = CCLabelTTF::create("tweet", "Helvetica", 32.0f);
        lblTweet->setPosition(ccp(btnTweet->getContentSize().width * 0.5f,
                                  lblTweet->getContentSize().height * 0.6f));
        btnTweet->addChild(lblTweet);
    }
    
    CCMenuItem *btnContinue = CCMenuItemImage::create(HS_RES_IMG("footer_continue"), HS_RES_IMG("footer_continue_h"));
    {
        btnContinue->setTag(TAG_MENU_CONTINUE);
        btnContinue->setTarget(this, menu_selector(HSPlayFooter::menuButtonFired));
        btnContinue->setPosition(ccp(grid.width * 0.0f, 0));
        btnContinue->setScale(menuScale);
        CCLabelTTF *lblContinue = CCLabelTTF::create("continue", "Helvetica", 32.0f);
        lblContinue->setPosition(ccp(btnContinue->getContentSize().width * 0.5f,
                                     lblContinue->getContentSize().height * 0.6f));
        btnContinue->addChild(lblContinue);
    }
    
    CCMenuItem *btnQuit = CCMenuItemImage::create(HS_RES_IMG("footer_quit"), HS_RES_IMG("footer_quit_h"));
    {
        btnQuit->setTag(TAG_MENU_QUIT);
        btnQuit->setTarget(this, menu_selector(HSPlayFooter::menuButtonFired));
        btnQuit->setPosition(ccp(grid.width * 1.0f, 0));
        btnQuit->setScale(menuScale);
        CCLabelTTF *lblQuit = CCLabelTTF::create("quit", "Helvetica", 32.0f);
        lblQuit->setPosition(ccp(btnQuit->getContentSize().width * 0.5f,
                                 lblQuit->getContentSize().height * 0.6f));
        btnQuit->addChild(lblQuit);
    }
    
    CCMenu *menu = CCMenu::create(btnTweet, btnContinue, btnQuit, NULL);
    menu->setPosition(ccp(size.width * 0.5f,
                          size.height - grid.height * 3.5f + menuTrans));
    this->addChild(menu);
    
    // Setup touch.
    
    return true;
}

void HSPlayFooter::menuButtonFired(CCObject *sender)
{
    CCNode *node = static_cast<CCNode *>(sender);
    switch (node->getTag()) {
        case TAG_MENU_TWEET:
            break;
        case TAG_MENU_CONTINUE:
            break;
        case TAG_MENU_QUIT:
            break;
        default:
            break;
    }
}

#pragma mark - Touch event handlers
bool HSPlayFooter::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    return true;
}
void HSPlayFooter::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    
}
void HSPlayFooter::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    
}
void HSPlayFooter::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{
    
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
