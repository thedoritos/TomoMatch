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
    
public:
    
    HSCardModel(const char* ownerId, const char* ownerImageUrl, const char* message);
    ~HSCardModel();
    
    const bool hasTheSameOwner(const HSCardModel &cardModel) const;
    
    const char* getOwnerId() const;
    const char* getOwnerImageUrl() const;
    const char* getMessage() const;
    
};

#endif /* defined(__TomoMatch__HSCardModel__) */
