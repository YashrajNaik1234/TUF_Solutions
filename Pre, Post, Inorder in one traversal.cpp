class Solution{
	public:
        vector<vector<int> > treeTraversal(TreeNode* root){
			//your code goes here
            vector<vector<int>> ans;
            if(!root) return ans;

            vector<int> pre, inO,post;

            stack<pair<TreeNode*, int>> st;
            st.push({root, 1});

            while(!st.empty()){
                auto it = st.top(); st.pop();

                if(it.second == 1){
                    pre.push_back(it.first -> val);
                    it.second++; st.push(it);

                    if(it.first -> left) st.push({it.first -> left, 1});
                }
                else if(it.second == 2){
                    post.push_back(it.first -> val);
                    it.second++; st.push(it);

                    if(it.first -> left) st.push({it.first -> right, 1});
                }
                else inO.push_back(it.first -> val);
            }

            ans.push_back(inO);
            ans.push_back(pre);
            ans.push_back(post);

            return ans;
		}
};
