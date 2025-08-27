class Solution {
public:
    double fractionalKnapsack(vector<long long>& val, vector<long long>& wt, long long capacity) {
        // Your code goes here
        vector<pair<double,pair<int,int>>> mp;
        for(int i(0);i < val.size();i++){
            mp.push_back({(double)(1.0 * val[i] / wt[i]), {val[i], wt[i]}});
        }

        sort(mp.rbegin(),mp.rend());

        double ans(0.000000); int j(0);
        while(capacity > 0 and j < mp.size()){
            if(mp[j].second.second <= capacity){
                capacity -= mp[j].second.second;
                ans += mp[j].second.first;
            }
            else{
                ans += mp[j].first * capacity; capacity = 0;
            } j++;
        }
        
        return ans;
    }
};
