//
//  HSPlayBoard.cpp
//  TomoMatch
//
//  Created by thedoritos on 2013/11/14.
//
//

#include "HSPlayBoard.h"


HSPlayBoard::HSPlayBoard()
{
    
}
HSPlayBoard::~HSPlayBoard()
{
    m_cardArray.clear();
}

bool HSPlayBoard::init()
{
    if (!CCNodeRGBA::init()) return false;
    
    CCSize visSize = CCDirector::sharedDirector()->getVisibleSize();
    CCSize gridSize = CCSizeMake(visSize.width / 3.0f, visSize.width / 3.0f);
    CCSize contSize = CCSizeMake(gridSize.width * 3.0f, gridSize.height * 4.0f);
    this->setContentSize(contSize);
    
    // Create cards.
    int numRows = 4;
    int numCols = 3;
    for (int iy = 0; iy < numRows; iy++) {
        for (int ix = 0; ix < numCols; ix++) {
            HSPlayCard *card = HSPlayCard::create();
            
            card->setPosition(ccp(gridSize.width  * ix + gridSize.width  * 0.5f,
                                  gridSize.height * iy + gridSize.height * 0.5f));
            this->addChild(card);
            
            m_cardArray.push_back(card);
        }
    }
    
    return true;
}

void HSPlayBoard::createCards(const vector<HSCardModel *>& cardModels)
{
    int numCards = fmin(m_cardArray.size(), cardModels.size());
    for (int i = 0; i < numCards; i++) {
        HSPlayCard *card = m_cardArray[i];
        card->setModel(cardModels[i]);
    }
}

bool HSPlayBoard::handleTouch(const CCPoint& pos)
{
    vector<HSPlayCard *>::iterator iter;
    for (iter = m_cardArray.begin(); iter != m_cardArray.end(); ++iter) {
        if ((*iter)->contains(pos)) {
            // Handle touch.
            (*iter)->showTail(0.3f, 1);
            
            return true;
        }
    }
    // Not handled.
    return false;
}
