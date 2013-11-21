//
//  HSGame.h
//  TomoMatch
//
//  Created by thedoritos on 2013/11/21.
//
//

#ifndef __TomoMatch__HSGame__
#define __TomoMatch__HSGame__

#include <vector>
#include "HSTwitter.h"
#include "HSCardModel.h"

using namespace std;
using namespace HSExtension;

class HSGameDelegate;

class HSGame : HSTwitterDelegate {
    
public:
    
    static HSGame * sharedInstance();
    
    void setDelegate(HSGameDelegate *delegate);
    
    void beginLoadingCards();
    
    const vector<HSCardModel *> & getCardModels();
    
private:
    
    HSGameDelegate *m_delegate;
    vector<HSCardModel *> m_cards;
    
    virtual void tweetsReceived(HSTwitter *twitter);

};

class HSGameDelegate {
public:
    virtual void onLoadingCardsCompleted(HSGame *game) = 0;
    virtual void onLoadingCardsFailed(HSGame *game) = 0;
};

#endif /* defined(__TomoMatch__HSGame__) */
