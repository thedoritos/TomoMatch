//
//  HSTitleLayer.cpp
//  TomoMatch
//
//  Created by thedoritos on 2013/11/14.
//
//

#include "HSTitleLayer.h"
#include "HSGame.h"
#include "HSAssets.h"

#include "HSBackground.h"
#include "HSPlayLayer.h"

bool HSTitleLayer::init()
{
    CCSize  visSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint visOrigin = CCDirector::sharedDirector()->getVisibleOrigin();
    
    // Create components.
    
    // Background.
    m_bgNode = HSBackground::create();
    this->addChild(m_bgNode);
    
    // Logo.
    CCSprite *logo = HS_CREATE_SPRITE(HS_RES_IMG("title_logo"));
    logo->setPosition(ccp(visOrigin.x + visSize.width  * 0.5f,
                          visOrigin.y + visSize.height - logo->getContentSize().height));
    this->addChild(logo);
    
    // Menu.
    CCMenuItemImage *startBtn = CCMenuItemImage::create(HS_RES_IMG("title_start"), HS_RES_IMG("title_start_hover"), this, menu_selector(HSTitleLayer::startGame));
    CCMenuItemImage *exitBtn = CCMenuItemImage::create(HS_RES_IMG("title_exit"), HS_RES_IMG("title_exit_hover"), this, menu_selector(HSTitleLayer::exitGame));
    
    CCMenu *menu = CCMenu::create(startBtn, exitBtn, NULL);
    menu->alignItemsVertically();
    menu->setPosition(ccp(visOrigin.x + visSize.width  * 0.5f,
                          visOrigin.y + visSize.height * 0.25f));
    this->addChild(menu);
    
    // Enable touch.
    this->setTouchMode(kCCTouchesOneByOne);
    this->setTouchEnabled(true);
    
    // Enable update.
    scheduleUpdate();
    
    return true;
}

CCScene* HSTitleLayer::scene()
{
    CCScene *scene = CCScene::create();
    CCLayer *layer = HSTitleLayer::create();
    scene->addChild(layer);
    return scene;
}

#pragma mark - Initialize
void HSTitleLayer::onEnterTransitionDidFinish()
{
    
}

#pragma mark - Update
void HSTitleLayer::update(float dt)
{
    m_bgNode->update(dt);
}

#pragma mark - Touch event handlers
bool HSTitleLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    return true;
}

void HSTitleLayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    
}

void HSTitleLayer::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    
}

void HSTitleLayer::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{
    
}

#pragma mark - Menu button actions
void HSTitleLayer::startGame()
{
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5f, HSPlayLayer::scene()));
}

void HSTitleLayer::exitGame()
{
    
}
