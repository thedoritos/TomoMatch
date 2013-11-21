//
//  HSPlayCard.cpp
//  TomoMatch
//
//  Created by thedoritos on 2013/11/14.
//
//

#include "HSPlayCard.h"

bool HSPlayCard::init()
{
    if (!CCNodeRGBA::init()) return false;
    
    return true;
}

void HSPlayCard::setCompleted(bool completed)
{
    m_isCompleted = completed;
}

void HSPlayCard::showHead(float duration, int numExtraTurns)
{
    
}
void HSPlayCard::showTail(float duration, int numExtraTurns)
{
    
}
