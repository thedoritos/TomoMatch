//
//  HSPlayHeader.cpp
//  TomoMatch
//
//  Created by thedoritos on 2013/11/14.
//
//

#include "HSPlayHeader.h"
#include "HSAssets.h"

const float HSPlayHeader::kHeight = 96.0f;

bool HSPlayHeader::init()
{
    if (!CCNodeRGBA::init()) return false;
    
    CCSize visSize = CCDirector::sharedDirector()->getVisibleSize();
//    CCPoint visOrigin = CCDirector::sharedDirector()->getVisibleOrigin();
    this->setContentSize(CCSizeMake(visSize.width, kHeight));
    
    // Setup background.
    CCSprite *bg = HS_CREATE_SPRITE(HS_RES_IMG("white"));
    bg->setScaleX(this->getContentSize().width / bg->getContentSize().width);
    bg->setScaleY(this->getContentSize().height / bg->getContentSize().height);
    bg->setColor(ccc3(0, 0, 0));
    bg->setOpacity(96);
    bg->setAnchorPoint(CCPointZero);
    bg->setPosition(CCPointZero);
    this->addChild(bg);
    
    // Create time meter.
    CCSprite *timer = HS_CREATE_SPRITE(HS_RES_IMG("header_timer"));
    timer->setAnchorPoint(ccp(0, 0.5));
    timer->setPosition(ccp(this->getContentSize().width  * 0.025f,
                           this->getContentSize().height * 0.5f));
    this->addChild(timer);
    
    m_timeLabel = CCLabelTTF::create("60\"00", "Helvetica", 44.0f);
    m_timeLabel->setAnchorPoint(ccp(0, 0.5));
    m_timeLabel->setPosition(ccp(timer->getPosition().x + timer->getContentSize().width + 20.0f,
                                 this->getContentSize().height * 0.5f));
    this->addChild(m_timeLabel);
    
    // Create life meter.
    CCSprite *life = HS_CREATE_SPRITE(HS_RES_IMG("header_heart"));
    life->setAnchorPoint(ccp(0, 0.5));
    life->setPosition(ccp(this->getContentSize().width * (0.025f + 0.400f),
                          this->getContentSize().height * 0.5f));
    this->addChild(life);
    
    m_lifeLabel = CCLabelTTF::create("3", "Helvetica", 44.0f);
    m_lifeLabel->setAnchorPoint(ccp(0, 0.5));
    m_lifeLabel->setPosition(ccp(life->getPosition().x + life->getContentSize().width + 20.0f,
                                 this->getContentSize().height * 0.5f));
    this->addChild(m_lifeLabel);
    
    // Create combo meter.
    CCSprite *combo = HS_CREATE_SPRITE(HS_RES_IMG("header_combo"));
    combo->setAnchorPoint(ccp(0, 0.5));
    combo->setPosition(ccp(this->getContentSize().width * (0.025f + 0.666f),
                           this->getContentSize().height * 0.5f));
    this->addChild(combo);
    
    m_comboLabel = CCLabelTTF::create("0", "Helvetica", 44.0f);
    m_comboLabel->setAnchorPoint(ccp(0, 0.5));
    m_comboLabel->setPosition(ccp(combo->getPosition().x + combo->getContentSize().width + 20.0f,
                                  this->getContentSize().height * 0.5f));
    this->addChild(m_comboLabel);
    
    return true;
}

void HSPlayHeader::setTime(float second)
{
    int secInt = (int) second;
    int secUnder = (int)((second - secInt) * 100);
    CCString *str = CCString::createWithFormat("%02d\"%02d", secInt, secUnder);
    m_timeLabel->setString(str->getCString());
}
void HSPlayHeader::setLife(int life)
{
    CCString *str = CCString::createWithFormat("%d", life);
    m_lifeLabel->setString(str->getCString());
}
void HSPlayHeader::setCombo(int combo)
{
    CCString *str = CCString::createWithFormat("%d", combo);
    m_lifeLabel->setString(str->getCString());
}
