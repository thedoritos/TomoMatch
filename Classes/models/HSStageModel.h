//
//  HSStageModel.h
//  TomoMatch
//
//  Created by thedoritos on 2013/11/14.
//
//

#ifndef __TomoMatch__HSStageModel__
#define __TomoMatch__HSStageModel__

#include "cocos2d.h"
#include "HSCardModel.h"

using namespace cocos2d;
using namespace std;

class HSStageDelegate;

class HSStageModel {
    
    CCString m_title;
    CCString m_subTitle;
    
    HSStageDelegate *m_delegate;
    
public:
    
    void update(float dt);
    
    const CCString & getTitle() const;
    const CCString & getSubTitle() const;
    
    void setTitle(const string& title);
    void setSubTitle(const string& subTitle);
    
    void setDelegate(HSStageDelegate *delegate);
    
    const vector<HSCardModel *> & getCards() const;
    void setCards(const vector<HSCardModel *>& cards);
    
private:
    
    vector<HSCardModel *> m_cards;
    
};

class HSStageDelegate {
public:
    virtual void onLoadingCardsCompleted(HSStageModel *stage) = 0;
    virtual void onLoadingCardsFailed(HSStageModel *stage) = 0;
};

#endif /* defined(__TomoMatch__HSStageModel__) */
