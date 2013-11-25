//
//  HSPlayBoard.h
//  TomoMatch
//
//  Created by thedoritos on 2013/11/14.
//
//

#ifndef __TomoMatch__HSPlayBoard__
#define __TomoMatch__HSPlayBoard__

#include "cocos2d.h"

#include "HSPlayCard.h"

//#include "HttpClient.h"
//#include "HttpRequest.h"
//#include "HttpResponse.h"

#include "HSAssets.h"

using namespace cocos2d;
using namespace std;

class HSPlayBoard : public CCNodeRGBA {
    
    vector<HSCardModel *> mCardModelArray;
    vector<HSPlayCard *> m_cardArray;
    
public:
    
    HSPlayBoard();
    ~HSPlayBoard();
    
    virtual bool init();
    CREATE_FUNC(HSPlayBoard);
    
    void createCards(const vector<HSCardModel *>& cardModels);
    
    bool handleTouch(const CCPoint& pos);
    
//    void onHttpRequestCompleted(cocos2d::extension::CCHttpClient* client, cocos2d::extension::CCHttpResponse* response);

//#pragma mark - HSAssetsDelegate
//    virtual void onLoadingAssetCompleted(HSAssets *loader, const char* key, const char* path);
//    virtual void onLoadingAssetFailed(HSAssets *loader, const char* key);
};

#endif /* defined(__TomoMatch__HSPlayBoard__) */
