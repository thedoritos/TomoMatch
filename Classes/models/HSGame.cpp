//
//  HSGame.cpp
//  TomoMatch
//
//  Created by thedoritos on 2013/11/21.
//
//

#include "HSGame.h"

HSGame * HSGame::sharedInstance()
{
    static HSGame *instance = 0;
    if (!instance) {
        instance = new HSGame();
    }
    return instance;
}

void HSGame::setDelegate(HSGameDelegate *delegate)
{
    m_delegate = delegate;
}

void HSGame::beginLoadingCards()
{
    HSTwitter *twitter = HSTwitter::sharedInstance();
    twitter->setDelegate(this);
    twitter->requestTimeline();
}

void HSGame::tweetsReceived(HSTwitter *twitter)
{
    vector<HSTweet *> timeLine = twitter->getTimeline();
    if (timeLine.size() > 0) {
        // Create cards.
        for (int i = 0; timeLine.size(); i++) {
            HSTweet *tweet = timeLine[i];
            HSCardModel *card = new HSCardModel(tweet->getUserName(), tweet->getUserImageUrl(), tweet->getMessage());
            m_cards.push_back(card);
        }
        // Notify delegate.
        if (m_delegate) {
            m_delegate->onLoadingCardsCompleted(this);
        }
    } else {
        if (m_delegate) {
            m_delegate->onLoadingCardsFailed(this);
        }
    }
}

const vector<HSCardModel *> & HSGame::getCardModels()
{
    return m_cards;
}
