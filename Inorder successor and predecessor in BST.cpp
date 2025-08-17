class Solution {
   public:
    vector<int> succPredBST(TreeNode* root, int key) {
        // your code goes here
        TreeNode* suc = nullptr;
        TreeNode* pre = nullptr;
        TreeNode* head = root;

        while (root) {
            if (key >= root->data) {
                root = root->right;
            } else {
                suc = root;
                root = root->left;
            }
        }

        root = head;

        while (root) {
            if (key <= root->data) {
                root = root->left;
            } else {
                pre = root;
                root = root->right;
            }
        }

        return {pre -> data, suc -> data};
    }
};
