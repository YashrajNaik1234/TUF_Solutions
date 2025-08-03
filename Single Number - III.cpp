class Solution{	
	public:		
		vector<int> singleNumber(vector<int>& nums){
			//your code goes here
            int cnt(0);
            for(auto i:nums) cnt = cnt ^ i;

            int index(0), x(cnt),i(0);
            while(true){
                if(x & (1 << i)){
                    index = i; break;
                }
                i++;
            }

            for(auto i:nums){
                if(i & (1 << index)) cnt = cnt ^ i;
            }

            vector<int> ans;
            ans.push_back(cnt);
            ans.push_back(x ^ cnt);

            sort(ans.begin(),ans.end());
            return ans;
		}
};
