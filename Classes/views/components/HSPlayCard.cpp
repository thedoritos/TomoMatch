//
//  HSPlayCard.cpp
//  TomoMatch
//
//  Created by thedoritos on 2013/11/14.
//
//

#include "HSPlayCard.h"
#include "HSAssets.h"

const int HSPlayCard::TAG_FRAME   = 1001;
const int HSPlayCard::TAG_MSG     = 1002;
const int HSPlayCard::TAG_USERIMG = 1003;

bool HSPlayCard::init()
{
    if (!CCNodeRGBA::init()) return false;
    
    // Create frame.
    CCSprite *frame = HS_CREATE_SPRITE(HS_RES_IMG("card_frame"));
    frame->setScale(1.05f);
    frame->setColor(ccc3(200, 200, 200));
    frame->setOpacity(226);
    frame->setTag(TAG_FRAME);
    this->addChild(frame);
    
    // Create text.
    CCLabelTTF *text = CCLabelTTF::create("This is a tweet message.", "Helvetica", 24.0f,
                                          CCSizeMake(frame->getContentSize().width * 0.95f,
                                                     frame->getContentSize().height * 0.95f),
                                          kCCTextAlignmentLeft, kCCVerticalTextAlignmentTop);
    text->setTag(TAG_MSG);
    text->setString("Re-initialized string.");
    this->addChild(text);
    
    // Create user image.
//    CCSprite *userImg = HS_CREATE_SPRITE(HS_RES_IMG("white"));
    
    // Setup properties.
    this->setContentSize(frame->boundingBox().size);
    
    m_isCompleted = false;
    m_isUpdated = false;
    
    return true;
}

void HSPlayCard::draw()
{
    CCNodeRGBA::draw();
    
    CCSprite *img = (CCSprite *) getChildByTag(TAG_USERIMG);
    if (img) {
        int rotation = (int) this->getRotationY() % 360;
//        printf("rotation :%f \n", rotation);
        img->setVisible(0 < rotation && rotation < 180);
    }
    
    if (m_isUpdated) {
        CCLabelTTF *text = (CCLabelTTF *) getChildByTag(TAG_MSG);
        if (text) {
            text->setString(m_model->getMessage());
        }
        
        CCSprite *img = HS_CREATE_SPRITE(m_model->getImageFilePath().c_str());
        img->setTag(TAG_USERIMG);
        
        CCSize texSize = img->getContentSize();
        
        float size = fminf(texSize.width, texSize.height);
        CCPoint offset = CCPointZero;
        if (texSize.width / texSize.height > 1.0f) {
            offset.setPoint((texSize.width - size) * 0.5f, 0.0f);
        } else {
            offset.setPoint(0.0f, (texSize.height - size) * 0.5f);
        }
        
        img->setTextureRect(CCRectMake(offset.x, offset.y, size, size));
        
        CCSprite *frame = (CCSprite *) getChildByTag(TAG_FRAME);
        if (frame) {
            img->setScale(frame->getContentSize().width / size);
        } else {
            img->setScale(100.0f / size);
        }
        
//        img->setVisible(false);
        this->addChild(img);
        
        m_isUpdated = false;
    }
}

void HSPlayCard::setModel(HSCardModel *cardModel)
{
    m_model = cardModel;
    m_isUpdated = true;
}

void HSPlayCard::setCompleted(bool completed)
{
    m_isCompleted = completed;
}

bool HSPlayCard::contains(const CCPoint &pos)
{
    CCRect bbox = this->boundingBox();
    
    CCRect rect = CCRectMake(bbox.origin.x - bbox.size.width * 0.5f,
                             bbox.origin.y - bbox.size.height * 0.5f,
                             bbox.size.width,
                             bbox.size.height);
    
    return rect.containsPoint(pos);
}

void HSPlayCard::showHead(float duration, int numExtraTurns)
{
    this->runAction(CCSequence::create(
            CCEaseExponentialOut::create(CCRotateBy::create(duration, 0, 0 + 360 * numExtraTurns)),
            CCRotateTo::create(0.1f, 0, 360),
            NULL)
    );
}
void HSPlayCard::showTail(float duration, int numExtraTurns)
{
    this->runAction(CCSequence::create(
            CCEaseExponentialOut::create(CCRotateBy::create(duration, 0, 180 + 360 * numExtraTurns)),
            CCRotateTo::create(0.1f, 0, 360),
            NULL)
    );
}
