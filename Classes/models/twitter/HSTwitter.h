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
        
        const char* m_userName;
        const char* m_userScreenName;
        const char* m_userImgUrl;
        const char* m_message;
        
    public:
        
        HSTweet(const char *userScreenName, const char *userName, const char *userImageUrl, const char *message){
            m_userScreenName = userScreenName;
            m_userName = userName;
            m_userImgUrl = userImageUrl;
            m_message = message;
        }
        ~HSTweet(){}
        
        const char *getUserScreenName() const { return m_userScreenName; }
        const char *getUserName() const { return m_userName; }
        const char *getUserImageUrl() const { return m_userImgUrl; }
        const char *getMessage() const { return m_message; }
    };
    
    class HSTwitterDelegate {
    public:
        virtual void tweetsReceived(HSTwitter *twitter){}
    };
}

#endif /* defined(__TomoMatch__HSTwitter__) */
