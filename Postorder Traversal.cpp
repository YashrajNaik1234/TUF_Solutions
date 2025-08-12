class Solution{
	public:
		vector<int> postorder(TreeNode* root){
	        //your code goes here
            vector<int> ans;
            if(!root) return ans;
            stack<TreeNode*> st1,st2; st1.push(root);

            while(!st1.empty()){
                TreeNode* node = st1.top(); st1.pop();
                st2.push(node);

                if(node -> left) st1.push(node -> left);
                else if(node -> right) st1.push(node -> right);
            }

            while(!st2.empty()){
                ans.push_back(st2.top() -> data); st2.pop();
            }

            return ans;
		}
};
