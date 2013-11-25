//
//  HSStageModel.cpp
//  TomoMatch
//
//  Created by thedoritos on 2013/11/14.
//
//

#include "HSStageModel.h"

const CCString & HSStageModel::getTitle() const
{
    return m_title;
}

const CCString & HSStageModel::getSubTitle() const
{
    return m_subTitle;
}

void HSStageModel::setDelegate(HSStageDelegate *delegate)
{
    m_delegate = delegate;
}

void HSStageModel::setTitle(const string& title)
{
    m_title = title;
}
void HSStageModel::setSubTitle(const string& subTitle)
{
    m_subTitle = subTitle;
}

const vector<HSCardModel *> & HSStageModel::getCards() const
{
    return m_cards;
}
void HSStageModel::setCards(const vector<HSCardModel *>& cards)
{
    m_cards = cards;
}
