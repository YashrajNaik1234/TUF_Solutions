class Solution {
public:
    int kDistinctChar(string& s, int k) {
        //your code goes here
        unordered_map<char,int> mp;
        
        int st(0),maxLen(0);
        for(int end(0);end < s.size();end++){
            mp[s[end]]++;

            while(mp.size() > k){
                mp[s[st]]--;
                if(mp[s[st]] == 0) mp.erase(s[st]);
                st++;
            }

            maxLen = max(maxLen, end - st + 1);
        }

        return maxLen;
    }
};
