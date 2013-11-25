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

void HSGame::beginLoadingStage()
{
    // Create new instnce.
    HSStageModel *orig = m_stage;
    m_stage = new HSStageModel();
    CC_SAFE_DELETE(orig);
    
    // Setup properties.
    m_stage->setTitle("Stage 1-1");
    m_stage->setSubTitle("The Beginning of The World");
    
    // Begin loading tweets.
    HSTwitter *twitter = HSTwitter::sharedInstance();
    twitter->setDelegate(this);
    twitter->requestTimeline();
}

void HSGame::tweetsReceived(HSTwitter *twitter)
{
    vector<HSTweet *> timeLine = twitter->getTimeline();
    if (timeLine.size() > 0) {
        // Get assets.
        HSAssets *assets = HSAssets::sharedInstance();
        assets->setDelegate(this);
        
        int maxCards = fmin(timeLine.size(), 12);
        
        // Create cards.
        for (int i = 0; i < maxCards; i++) {
            HSTweet *tweet = timeLine[i];
            
            HSCardModel *card = new HSCardModel(tweet->getUserScreenName(), tweet->getUserImageUrl(), tweet->getMessage());
            m_cards.push_back(card);
            
        }
        
        // Begin loading images.
        for (int i = 0; i < m_cards.size(); i++) {
            HSTweet *tweet = timeLine[i];
            assets->beginLoading(tweet->getUserScreenName().c_str(), tweet->getUserImageUrl().c_str());
        }
        
    } else {
        
        m_stage->setCards(m_cards);
        
        if (m_delegate) {
            m_delegate->onLoadingStageFailed(this);
        }
    }
}

#pragma mark - HSAssetDelegate
void HSGame::onLoadingAssetCompleted(HSAssets *loader, const char* key, const char* path)
{
    // Set the path to the loaded image to the models.
    for (int i = 0; i < m_cards.size(); i++) {
        HSCardModel *card = m_cards[i];
        if (card->isOwnerEquals(key)) {
            card->setImageFilePath(path);
        }
    }
    
    // Check completed.
    bool isPrepared = true;
    for (int i = 0; i < m_cards.size(); i++) {
        isPrepared = isPrepared && m_cards[i]->isPrepared();
    }
    if (isPrepared) {
        
        m_stage->setCards(m_cards);
        
        if (m_delegate) {
            m_delegate->onLoadingStageCompleted(this);
        }
    }
}

void HSGame::onLoadingAssetFailed(HSAssets *loader, const char* key)
{
    // Set the path to the NotFoundImage to the models.
    for (int i = 0; i < m_cards.size(); i++) {
        HSCardModel *card = m_cards[i];
        if (card->isOwnerEquals(key)) {
            card->setImageFilePath("not_found_image.png");
        }
    }
    
    // Check completed.
    bool isPrepared = true;
    for (int i = 0; i < m_cards.size(); i++) {
        isPrepared = isPrepared && m_cards[i]->isPrepared();
    }
    if (isPrepared) {
        if (m_delegate) {
            m_delegate->onLoadingStageCompleted(this);
        }
    }
}

const vector<HSCardModel *> & HSGame::getCardModels()
{
    return m_cards;
}

HSStageModel* HSGame::getStage()
{
    return m_stage;
}