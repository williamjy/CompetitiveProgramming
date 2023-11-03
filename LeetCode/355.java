import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.SortedMap;
import java.util.TreeMap;



class Twitter {
    private Integer m_timeStamp = 0;
    private Map<Integer, List<Integer>> m_followerMap;
    private Map<Integer, SortedMap<Integer, Integer>> m_UserIdToTweetTimeStamp;
    

    public Twitter() {
        m_followerMap = new HashMap<Integer, List<Integer>>();
        m_UserIdToTweetTimeStamp = new HashMap<Integer, SortedMap<Integer, Integer>>();
    }
    
    public void postTweet(int userId, int tweetId) {
        if (!m_UserIdToTweetTimeStamp.containsKey(userId)) {
            Comparator<Integer> comparator = new Comparator<Integer>(){
            @Override
            public int compare(final Integer a, final Integer b){
                return b - a;
            }
        };
            m_UserIdToTweetTimeStamp.put(userId, new TreeMap<Integer, Integer>(comparator));
        }
        m_UserIdToTweetTimeStamp.get(userId).put(m_timeStamp++, tweetId);
    }
    
    public List<Integer> getNewsFeed(int userId) {
        List<Integer> result = new ArrayList<Integer>();
        Comparator<Integer> comparator = new Comparator<Integer>() {
            @Override
            public int compare(final Integer a, final Integer b) {
                return b - a;
            }
        };
        SortedMap<Integer, Integer> sortedMap = new TreeMap<Integer, Integer>(comparator);
        if (m_UserIdToTweetTimeStamp.containsKey(userId)) {
            var userMap = m_UserIdToTweetTimeStamp.get(userId);
            if (userMap != null && userMap.size() > 0) {
                sortedMap.putAll(m_UserIdToTweetTimeStamp.get(userId));
            }
        }
        if (!m_followerMap.isEmpty()) {
            for (int followeeId : m_followerMap.get(userId)) {
                var followeeMap = m_UserIdToTweetTimeStamp.get(followeeId);
                if (followeeMap != null && followeeMap.size() > 0) {
                    sortedMap.putAll(followeeMap);
                }
            }
        }
        int count = 10;
        for (int timeStamp : sortedMap.keySet()) {
            if (count == 0) {
                break;
            }
            result.add(sortedMap.get(timeStamp));
            count--;
        }
        return result;
    }
    
    public void follow(int followerId, int followeeId) {
        if (!m_followerMap.containsKey(followerId)) {
            m_followerMap.put(followerId, new ArrayList<Integer>());
        }
        m_followerMap.get(followerId).add(followeeId);
    }
    
    public void unfollow(int followerId, int followeeId) {
        if (m_followerMap.containsKey(followerId)) {
            if (m_followerMap.get(followerId).contains(followeeId)) {
                m_followerMap.get(followerId).remove(Integer.valueOf(followeeId));
            }
        }
    }
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * List<Integer> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */