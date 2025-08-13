class Solution{
    public:
    vector<int> topView(TreeNode *root){
        //your code goes here
        vector<int> ans;
        if(!root) return ans;

        map<int,int> mp;
        queue<pair<TreeNode*,int>> q;
        q.push({root, 0});

        while(!q.empty()){
            auto x = q.front(); q.pop();

            TreeNode* node = x.first;
            int v = x.second;

            if(mp.find(v) == mp.end()) mp[v] = node -> data;

            if(node -> left) q.push({node -> left, v - 1});
            if(node -> right) q.push({node -> right, v + 1});
        }

        for(auto i: mp){
            ans.push_back(i.second);
        }

        return ans;
    }
};
