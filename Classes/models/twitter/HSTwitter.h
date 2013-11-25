//
//  HSTwitter.h
//  TomoMatch
//
//  Created by thedoritos on 2013/11/14.
//
//

#ifndef __TomoMatch__HSTwitter__
#define __TomoMatch__HSTwitter__

#include <stddef.h>
#include <string>
#include <vector>

namespace HSExtension {
    
    class HSTweet;
    class HSTwitterDelegate;
    
    class HSTwitter {
        
        HSTwitterDelegate *m_delegate;
        std::vector<HSTweet *> m_tweetsReceived;
        
    public:
        
        static HSTwitter * sharedInstance();
        
        void setDelegate(HSTwitterDelegate *deletage);
        
        /**
         * Inflates dialog to post new tweet.
         */
        void showTweetDialog(const char *message);
        
        /**
         * Sends request to get user's timeline.
         */
        void requestTimeline();
        
        /**
         * Returns true if the app has the permission to
         * access to a Twitter account.
         */
        bool isEnabled();
        
        /**
         * Returns tweets have been received by HSTwitter#requestTimeline.
         */
        std::vector<HSTweet *> getTimeline();
        
    };
    
    class HSTweet {
        
        std::string mUserName;
        std::string mUserScreenName;
        std::string mUserImageUrl;
        std::string mMessage;
        
    public:
        
        HSTweet(const char *userScreenName, const char *userName, const char *userImageUrl, const char *message)
        :mUserName(userName)
        ,mUserScreenName(userScreenName)
        ,mUserImageUrl(userImageUrl)
        ,mMessage(message)
        {}
        
        ~HSTweet(){}
        
        const std::string & getUserScreenName() const { return mUserScreenName; }
        const std::string & getUserName() const { return mUserName; }
        const std::string getUserImageUrl() const {
            std::string base = mUserImageUrl;
            std::size_t begin = base.rfind("_normal");
            base.replace(begin, 7, "");
            return base;
        }
        const std::string & getMessage() const { return mMessage; }
    };
    
    class HSTwitterDelegate {
    public:
        virtual void tweetsReceived(HSTwitter *twitter){}
    };
}

#endif /* defined(__TomoMatch__HSTwitter__) */
