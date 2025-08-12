class Solution{
	public:
		vector<int> inorder(TreeNode* root){
	        //your code goes here
            vector<int> ans;
            if(root == nullptr) return ans;

            TreeNode* node = root;
            stack<TreeNode*> st;
            while(true){
                if(node != nullptr){
                    st.push(node); node = node -> left;
                }
                else{
                    if(st.empty()) break;
                    node = st.top(); st.pop();
                    ans.push_back(node -> data);
                    node = node -> right;
                }
            }

            return ans;
		}
};
