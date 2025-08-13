class Solution {
public:
    bool solve(TreeNode* &root){
        if(!root) return true;
        if(!root -> left and !root -> right) return true;
        int leftSum = (root -> left) ? root -> left -> val : 0;
        int rightSum = (root -> right) ? root -> right -> val : 0;
        
        if(root ->val != leftSum + rightSum) return false;
        return solve(root -> left) and solve(root -> right);
    }
    bool checkChildrenSum(TreeNode* root) {
        // Your code goes here
        return solve(root);
    }
};
