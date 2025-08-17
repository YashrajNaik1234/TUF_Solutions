class Node{
    int maxNode, minNode, maxSize;

    Node(int minNode,int maxNode, int maxSize){
        this -> maxNode = maxNode;
        this -> minNode = minNode;
        this -> maxSize = maxSize;
    }
};

class Solution{
	public:
        Node largestSolveBST(TreeNode* root){
            if(!root) return Node(INT_MAX, INT_MIN, 0);

            auto left = largestSolveBST(root -> left);
            auto right = largestSolveBST(root -> right);

            if(left.maxNode < root -> data and root -> data < right.minNode){
                return Node(min(root -> data, left.minNode), max(root -> data, right.maxNode), left.maxSize + right.maxSize + 1);
            }

            return Node(INT_MAX, INT_MIN, max(left.maxSize, right.maxSize));
        }
		int largestBST(TreeNode* root){
			//your code goes here
            return largestSolveBST(root).maxSize;
		}
};
