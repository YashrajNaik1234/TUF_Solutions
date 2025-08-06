class Solution{
  public:
    int maxScore(vector<int>& cardScore , int k){
        //your code goes here
        int ans(0),sum(0);
        for(int i(0);i < k;i++) sum += cardScore[i];
        ans = sum; int end(cardScore.size() - 1);

        for(int i(k - 1);i >= 0;i--){
            sum -= cardScore[i];
            sum += cardScore[end--];
            ans = max(ans, sum);
        }

        return ans;
    }
};
