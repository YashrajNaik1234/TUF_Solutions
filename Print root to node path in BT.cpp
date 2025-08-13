class Solution{
	public:
        bool isLeaf(TreeNode* root){
            if(!root -> left and !root -> right) return true;
            return false;
        }
        void solvePath(TreeNode* root, vector<vector<int>>& ans, vector<int> x){
            x.push_back(root -> data);
            
            if(isLeaf(root)){
                ans.push_back(x); return;
            }

            if(root -> left) solvePath(root -> left, ans, x);
            if(root -> right) solvePath(root -> right, ans, x);

            x.pop_back();
            return;
        }
		vector<vector<int>> allRootToLeaf(TreeNode* root) {
            //your code goes here
            vector<vector<int>> ans;
            if(!root) return ans;
            vector<int> x;
            solvePath(root, ans, x);
            return ans;
		}
};
