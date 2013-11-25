//
//  HSPlayCard.h
//  TomoMatch
//
//  Created by thedoritos on 2013/11/14.
//
//

#ifndef __TomoMatch__HSPlayCard__
#define __TomoMatch__HSPlayCard__

#include "cocos2d.h"
#include "HSCardModel.h"

using namespace cocos2d;
using namespace std;

class HSPlayCard : public CCNodeRGBA {
    
    bool m_isCompleted;
    bool m_isUpdated;
    HSCardModel *m_model;
    
    static const int TAG_FRAME;
    static const int TAG_MSG;
    static const int TAG_USERIMG;
    
    string m_message;
    
public:
    
    virtual void draw();
    
    virtual bool init();
    CREATE_FUNC(HSPlayCard);
    
    void setModel(HSCardModel *cardModel);
    
    void setCompleted(bool completed);
    
    bool contains(const CCPoint &pos);
    
    void showHead(float duration, int numExtraTurns = 0);
    void showTail(float duration, int numExtraTurns = 0);
    
};

#endif /* defined(__TomoMatch__HSPlayCard__) */
