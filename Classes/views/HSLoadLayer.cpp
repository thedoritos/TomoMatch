//
//  HSLoadLayer.cpp
//  TomoMatch
//
//  Created by thedoritos on 2013/11/14.
//
//

#include "HSLoadLayer.h"

bool HSLoadLayer::init()
{
    return true;
}

void HSLoadLayer::setStageModel(const HSStageModel *stageModel)
{
    m_stageSubTitle = stageModel->getTitle();
    m_stageSubTitle = stageModel->getSubTitle();
}