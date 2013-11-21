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

using namespace cocos2d;
using namespace std;

class HSPlayBoard : public CCNodeRGBA {
    
    vector<HSPlayCard *> m_cardArray;
    
public:
    
    virtual bool init();
    CREATE_FUNC(HSPlayBoard);
    
};

#endif /* defined(__TomoMatch__HSPlayBoard__) */
