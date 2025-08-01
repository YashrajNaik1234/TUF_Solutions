class Solution{
    public:
    void solve(int i, int n, vector<int>& v, int sum, int k, int& ans){
        if(sum == k){
            ans++; return;
        }
        if(i == n) return;
        solve(i + 1, n, v, sum + v[i], k, ans);
        solve(i + 1, n, v, sum, k, ans);
    }
    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    	//your code goes here
        int ans = 0;
        solve(0, nums.size(), nums, 0, k, ans);
        return ans;
    }
};
