//
//  HSCardModel.cpp
//  TomoMatch
//
//  Created by thedoritos on 2013/11/14.
//
//

#include "HSCardModel.h"

HSCardModel::HSCardModel(const char* ownerId, const char* ownerImageUrl, const char* message)
{
    m_ownerName = ownerId;
    m_ownerImageUrl = ownerImageUrl;
    m_message = message;
}
HSCardModel::~HSCardModel()
{
    
}

const bool HSCardModel::hasTheSameOwner(const HSCardModel &cardModel) const
{
    return m_ownerName.compare(cardModel.m_ownerName) == 0;
}

const char* HSCardModel::getOwnerId() const
{
    return m_ownerName.c_str();
}
const char* HSCardModel::getOwnerImageUrl() const
{
    return m_ownerImageUrl.c_str();
}
const char* HSCardModel::getMessage() const
{
    return m_message.c_str();
}
