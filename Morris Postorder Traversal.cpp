class Solution {
public:
    vector<int> postorder(TreeNode* root) {
        vector<int> ans;

        TreeNode* cur = root;
        while (cur != nullptr) {
            if (cur -> right == nullptr) {
                ans.push_back(cur -> data);
                cur = cur -> left;
            } else {
                TreeNode* prev = cur -> right;
                while (prev -> left != nullptr && prev -> left != cur) {
                    prev = prev -> left;
                }

                if (prev -> left == nullptr) {
                    prev -> left = cur;
                    ans.push_back(cur -> data);
                    cur = cur -> right;
                } else {
                    prev -> left = nullptr;
                    cur = cur -> left;
                }
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
