class Solution
{
public:
    vector<int> nextSmallerElements(const vector<int> &arr)
    {
        // Your code goes here
        stack<pair<int,int>> s;
        vector<int> ans(arr.size());

        for(int i(0);i < arr.size();i++){
            while(!s.empty() and s.top().first > arr[i]){
                ans[s.top().second] = arr[i]; s.pop();
            }
            s.push({arr[i],i});
        }

        while(!s.empty()){
            ans[s.top().second] = -1; s.pop();
        }

        return ans;
    }
};
