//
//  HSCardModel.h
//  TomoMatch
//
//  Created by thedoritos on 2013/11/14.
//
//

#ifndef __TomoMatch__HSCardModel__
#define __TomoMatch__HSCardModel__

#include <iostream>
#include <cstdio>

using namespace std;

class HSCardModel {
    
    string m_ownerName;
    string m_ownerImageUrl;
    string m_message;
    
    string mOwnerImageFilePath;
    
public:
    
    HSCardModel(const string &ownerId, const string &ownerImageUrl, const string &message);
    ~HSCardModel();
    
    const bool isOwnerEquals(const string &owner) const;
    const bool isOwnerEquals(const HSCardModel &cardModel) const;
    
    void setImageFilePath(const string &path);
    const string & getImageFilePath() const;
    
    const bool isPrepared() const;
    
    
    
    const bool hasTheSameOwner(const HSCardModel &cardModel) const;
    
    const char* getOwnerId() const;
    const char* getOwnerImageUrl() const;
    const char* getMessage() const;
    
};

#endif /* defined(__TomoMatch__HSCardModel__) */
