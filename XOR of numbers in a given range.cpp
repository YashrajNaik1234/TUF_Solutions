class Solution {
   public:
    int findRangeXOR(int l, int r) {
        // your code goes here
        int ans(0);
        for (int i(l); i <= r; i++) ans = ans ^ i;
        return ans;
    }
};
