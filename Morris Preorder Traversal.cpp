class Solution {
   public:
    vector<int> preorder(TreeNode* root) {
        // your code goes here
        vector<int> ans;

        TreeNode* cur = root;
        while (cur != nullptr) {
            if (cur->left == nullptr) {
                ans.push_back(cur->data);
                cur = cur->right;
            } else {
                TreeNode* prev = cur->left;
                while (prev->right != nullptr && prev->right != cur) {
                    prev = prev->right;
                }

                if (prev->right == nullptr) {
                    ans.push_back(cur->data);
                    prev->right = cur;
                    cur = cur->left;
                } else {
                    prev->right = nullptr;
                    cur = cur->right;
                }
            }
        }

        return ans;
    }
};
