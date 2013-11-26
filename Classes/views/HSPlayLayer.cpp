//
//  HSPlayLayer.cpp
//  TomoMatch
//
//  Created by thedoritos on 2013/11/14.
//
//

#include "HSPlayLayer.h"
#include "HSTitleLayer.h"
#include "HSAssets.h"

bool HSPlayLayer::init()
{
    CCSize  visSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint visOrigin = CCDirector::sharedDirector()->getVisibleOrigin();
    
    // Setup models.
    HSGame *game = HSGame::sharedInstance();
    game->setDelegate(this);
    game->beginLoadingStage();
    
    // Create components.
    static const ccColor3B kTuyukusa = ccc3( 46, 169, 223);
    static const ccColor3B kWakatake = ccc3( 93, 172, 129);
    static const ccColor3B kKohbai   = ccc3(225, 107, 140);
    
    m_background = HSBackground::create();
    m_background->setColor(kWakatake);
    m_background->setLabel("Level 1");
    this->addChild(m_background);
    
    m_header = HSPlayHeader::create();
    m_header->setAnchorPoint(ccp(0, 1));
    m_header->setPosition(ccp(visOrigin.x, visOrigin.y + visSize.height));
    this->addChild(m_header, 1);
    
    m_footer = HSPlayFooter::create();
    m_footer->setAnchorPoint(ccp(0, 1));
    m_footer->setPosition(ccp(visOrigin.x, visOrigin.y));
    m_footer->setVisible(false);
    m_footer->setDelegate(this);
    this->addChild(m_footer, 1);
    
    m_board = HSPlayBoard::create();
    m_board->setAnchorPoint(ccp(0, 1));
    m_board->setPosition(ccp(visOrigin.x,
                             visOrigin.y + visSize.height - HSPlayHeader::kHeight));
    this->addChild(m_board);
    
    // Enable touch.
    this->setTouchMode(kCCTouchesOneByOne);
    this->setTouchEnabled(true);
    
    // Enable update.
    scheduleUpdate();
    
    return true;
}

CCScene* HSPlayLayer::scene()
{
    CCScene *scene = CCScene::create();
    CCLayer *layer = HSPlayLayer::create();
    scene->addChild(layer);
    return scene;
}

#pragma mark - Update
void HSPlayLayer::update(float dt)
{
    static float time = 60.0f;
    if (time == -1.0f) {
        
    } else {
        if (time - dt < 0.0f) {
            time = -1.0f;
            // completed
            m_header->setTime(0.0f);
            
        } else {
            time -= dt;
            m_header->setTime(time);
        }
    }
    
    m_background->update(dt);
    
}

#pragma mark - Touch event handlers
bool HSPlayLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    return true;
}
void HSPlayLayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    
}
void HSPlayLayer::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    // Touch cards.
    bool handled = m_board->handleTouch(pTouch->getLocation());
    if (handled) {
        return;
    }
    
    // Show or dispose footer.
    if (!m_footer->isVisible()) {
        m_footer->show(0.5f);
    } else {
        m_footer->dispose(0.5f);
    }
    
//    CCDirector::sharedDirector()->replaceScene(HSTitleLayer::scene());
}
void HSPlayLayer::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{
    
}

#pragma mark - HSGameDelegate
void HSPlayLayer::onLoadingStageCompleted(HSGame *game)
{
    m_board->createCards(HSGame::sharedInstance()->getStage()->getCards());
}
void HSPlayLayer::onLoadingStageFailed(HSGame *game)
{
    
}

#pragma mark - HSPlayFooterDelegate
void HSPlayLayer::onTweetButtonFired(HSPlayFooter *footer)
{
    HSTwitter *twitter = HSTwitter::sharedInstance();
    twitter->showTweetDialog(footer->getMessage());
}
void HSPlayLayer::onContinueButtonFired(HSPlayFooter *fotter)
{
    
}
void HSPlayLayer::onQuitButtonFired(HSPlayFooter *fotter)
{
    HSGame *game = HSGame::sharedInstance();
    
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5f, HSTitleLayer::scene()));
}