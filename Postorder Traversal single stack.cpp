class Solution{
	public:
		vector<int> postorder(TreeNode* root){
	        //your code goes here
            vector<int> ans;
            if(!root) return ans;
            stack<TreeNode*> st;
            TreeNode* node = root;

            while(!st.empty() or node){
                if(node){
                    st.push(node); node = node -> left;
                }
                else{
                    TreeNode* temp = st.top() -> right;
                    if(temp == nullptr){
                        temp = st.top(); st.pop(); ans.push_back(temp -> val);
                        while(!st.empty() and temp == st.top() -> right){
                            temp = st.top(); st.pop(); ans.push_back(temp -> val);
                        }
                    }
                    else node = temp;
                }
            }

            return ans;
		}
};
