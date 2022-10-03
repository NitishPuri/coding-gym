// https://leetcode.com/problems/tweet-counts-per-frequency/

#include <map>
#include <vector>
#include <string>
using namespace std;

class TweetCounts {
    map<string, map<int, int>> tweets;
    int getChunkSize(const string& freq) {
        if(freq == "minute") return 60;
        if(freq == "hour") return 3600;
        if(freq == "day") return 86400;
        return 0;
    }
public:
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        // tweets[tweetName].push_back(time);
        tweets[tweetName][time]++;
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        auto chunkSize = getChunkSize(freq);
        vector<int> res( (endTime - startTime) / chunkSize + 1, 0);
                
        auto& tweets_for_name = tweets[tweetName];
        auto start = tweets_for_name.lower_bound(startTime);
        auto end = tweets_for_name.upper_bound(endTime);
        while(start != end) {
            res[(start->first - startTime) / chunkSize] += start->second;
            start++;
        }
                        
        return res;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */

int main() {
    TweetCounts t;
    t.recordTweet("tweet3", 0);
    t.recordTweet("tweet3", 60);
    t.recordTweet("tweet3", 10);
    t.getTweetCountsPerFrequency("minute", "tweet3", 0, 59);
    t.getTweetCountsPerFrequency("minute", "tweet3", 0, 60);
    t.recordTweet("tweet3", 120);
    t.getTweetCountsPerFrequency("hour", "tweet3", 0, 210);
}