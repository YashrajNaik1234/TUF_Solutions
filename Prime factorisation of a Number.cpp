class Solution {
   public:
    vector<int> primeFactors(int n) {
        vector<int> x;
        while (n % 2 == 0) {
            x.push_back(2);
            n = n / 2;
        }

        for (int i = 3; i * i <= n; i = i + 2) {
            while (n % i == 0) {
                x.push_back(i); n = n / i;
            }
        }

        if (n > 2) x.push_back(n);
        return x;
    }
    vector<vector<int>> primeFactors(vector<int>& queries) {
        // your code goes here
        vector<vector<int>> ans;
        for(int i(0);i < queries.size();i++){
            ans.push_back(primeFactors(queries[i]));
        }

        return ans;
    }
};
