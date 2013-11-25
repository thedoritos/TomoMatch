//
//  HSCardModel.cpp
//  TomoMatch
//
//  Created by thedoritos on 2013/11/14.
//
//

#include "HSCardModel.h"

HSCardModel::HSCardModel(const string &ownerId, const string &ownerImageUrl, const string &message)
{
    m_ownerName = ownerId;
    m_ownerImageUrl = ownerImageUrl;
    m_message = message;
}
HSCardModel::~HSCardModel()
{
    
}

const bool HSCardModel::isOwnerEquals(const string &owner) const
{
    return m_ownerName.compare(owner) == 0;
}
const bool HSCardModel::isOwnerEquals(const HSCardModel &cardModel) const
{
    return this->isOwnerEquals(cardModel.getOwnerId());
}

void HSCardModel::setImageFilePath(const string &path)
{
    mOwnerImageFilePath = path;
}
const string & HSCardModel::getImageFilePath() const
{
    return mOwnerImageFilePath;
}

const bool HSCardModel::hasTheSameOwner(const HSCardModel &cardModel) const
{
    return m_ownerName.compare(cardModel.m_ownerName) == 0;
}

const bool HSCardModel::isPrepared() const
{
    return mOwnerImageFilePath.compare("") != 0;
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
