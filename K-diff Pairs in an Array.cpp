class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int,int> mp;
        
        int ans(0);
        for(auto i:nums) mp[i]++;

        for(auto i:mp){
            if(mp.count(i.first + k) > 0 and k != 0) ans++;
            if(k == 0 and i.second > 1) ans++;
        }

        return ans;
    }
};
