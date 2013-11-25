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
#include "HSAssets.h"
#include "HSStageModel.h"
#include "HSCardModel.h"

using namespace std;
using namespace HSExtension;

class HSGameDelegate;

class HSGame : HSTwitterDelegate, HSAssetsDelegate {
    
public:
    
    static HSGame * sharedInstance();
    
    void setDelegate(HSGameDelegate *delegate);
    
    
    void beginLoadingStage();
    
    
    const vector<HSCardModel *> & getCardModels();
    
    
    HSStageModel* getStage();
    
#pragma mark - HSAssetDelegate
    virtual void onLoadingAssetCompleted(HSAssets *loader, const char* key, const char* path);
    virtual void onLoadingAssetFailed(HSAssets *loader, const char* key);
    
private:
    
    HSGameDelegate *m_delegate;
    
    vector<HSCardModel *> m_cards;
    HSStageModel *m_stage;
    
    virtual void tweetsReceived(HSTwitter *twitter);
    
};

class HSGameDelegate {
public:
    virtual void onLoadingStageCompleted(HSGame *game) = 0;
    virtual void onLoadingStageFailed(HSGame *game) = 0;
};

#endif /* defined(__TomoMatch__HSGame__) */
