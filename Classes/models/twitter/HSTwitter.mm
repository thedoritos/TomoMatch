//
//  HSTwitter.mm
//  TomoMatch
//
//  Created by thedoritos on 2013/11/15.
//
//

#include "HSTwitter.h"

#import <Foundation/Foundation.h>
#import <Social/Social.h>
#import <Accounts/Accounts.h>

namespace HSExtension
{
    static HSTwitter *s_pTwitter;
    
    HSTwitter* HSTwitter::sharedInstance()
    {
        if (!s_pTwitter) {
            s_pTwitter = new HSTwitter();
        }
        return s_pTwitter;
    }
    
    void HSTwitter::setDelegate(HSTwitterDelegate *delegate)
    {
        m_delegate = delegate;
    }
    
    void HSTwitter::showTweetDialog(const char *message)
    {
        // Setup ViewController for twitter.
        SLComposeViewController *twtVC = [SLComposeViewController composeViewControllerForServiceType:SLServiceTypeTwitter];
        [twtVC setInitialText:[NSString stringWithUTF8String:message]];
        
        // Present the VC.
        UIViewController *appVC = [UIApplication sharedApplication].keyWindow.rootViewController;
        [appVC presentViewController:twtVC animated:YES completion:^(void){
            NSLog(@"Twitter dialog did open.");
        }];
    }
    
    void HSTwitter::requestTimeline()
    {
        ACAccountStore *accStore = [[ACAccountStore alloc] init];
        ACAccountType  *accType  = [accStore accountTypeWithAccountTypeIdentifier:ACAccountTypeIdentifierTwitter];
        
        [accStore requestAccessToAccountsWithType:accType options:nil completion:^(BOOL granted, NSError *error){
            if (!granted) {
                NSLog(@"App doesn't have permission to use twitter accounts.");
                if (m_delegate) {
                    m_delegate->tweetsReceived(this);
                }
                
            } else {
                NSArray *accArray = [accStore accountsWithAccountType:accType];
                if (accArray.count == 0) {
                    NSLog(@"Twitter accounts not found on device.");
                    if (m_delegate) {
                        m_delegate->tweetsReceived(this);
                    }
                    
                } else {
                    NSURL *url = [NSURL URLWithString:@"https://api.twitter.com/1.1/statuses/home_timeline.json"];
                    SLRequest *request = [SLRequest requestForServiceType:SLServiceTypeTwitter requestMethod:SLRequestMethodGET URL:url parameters:nil];
                    
                    // TODO we want to choose account to use !!!
                    [request setAccount:[accArray objectAtIndex:0]];
                    
                    [request performRequestWithHandler:^(NSData *responseData, NSHTTPURLResponse *urlResponse, NSError *error){
                        NSUInteger statusCode = urlResponse.statusCode;
                        if (statusCode < 200 || statusCode >= 300) {
                            NSLog(@"Twitter request failed with status code '%d'", statusCode);
                            if (m_delegate) {
                                m_delegate->tweetsReceived(this);
                            }
                            
                        } else {
                            NSArray *tweets = [NSJSONSerialization JSONObjectWithData:responseData options:NSJSONReadingAllowFragments error:nil];
                            if (tweets) {
                                NSLog(@"Timeline has been received.");
                                
                                for (NSDictionary *dic in tweets) {
                                    
                                    NSDictionary *user = [dic objectForKey:@"user"];
                                    NSString *userScreenName = [user objectForKey:@"screen_name"];
                                    NSString *userName = [user objectForKey:@"name"];
                                    NSString *userImageUrl = [user objectForKey:@"profile_image_url"];
                                    NSString *message  = [dic objectForKey:@"text"];
                                    
                                    NSLog(@"Tweet [user=%@, text=%@] has been stored.", userScreenName, message);
                                    
                                    HSTweet *tweet = new HSTweet([userScreenName UTF8String], [userName UTF8String], [userImageUrl UTF8String],[message UTF8String]);
                                    m_tweetsReceived.push_back(tweet);
                                }
                                
                                if (m_delegate) {
                                    m_delegate->tweetsReceived(this);
                                }
                            } else {
                                NSLog(@"Timeline hasn't been received.");
                                if (m_delegate) {
                                    m_delegate->tweetsReceived(this);
                                }
                            }
                        }
                    }];
                }
            }
        }];
    }
    
    bool HSTwitter::isEnabled()
    {
        // TODO implement !!!
        return true;
    }
    
    std::vector<HSTweet *> HSTwitter::getTimeline()
    {
        return m_tweetsReceived;
    }
}