class Solution
{
public:
    void solve(int i, int n, vector<int>& v, int sum, vector<int>& ans){
        if(i >= n){
            ans.push_back(sum); return;
        }

        solve(i + 1, n, v, sum, ans);
        solve(i + 1, n, v, sum + v[i], ans);
    }
    vector<int> subsetSums(vector<int> &nums)
    {
        // your code goes here
        vector<int> ans;
        solve(0, nums.size(), nums, 0, ans);
        return ans;
    }
};
