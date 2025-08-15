class Solution{	
	public:
        int floor(TreeNode* root, int key){
            int floor(-1);
            while(root){
                if(root -> data == key){
                    return key;
                }

                if(key > root -> data){
                    floor = root -> data;
                    root = root -> right;
                }
                else{
                    root = root -> left;
                }
            }
            return floor;
        }
        int ceil(TreeNode* root, int key){
            int ceil(-1);
            while(root){
                if(root -> data == key){
                    return key;
                }

                if(key > root -> data){
                    root = root -> right;
                }
                else{
                    ceil = root -> data;
                    root = root -> left;
                }
            }
            return ceil;
        }
		vector<int> floorCeilOfBST(TreeNode* root,int key){
			//your code goes here
            return {ceil(root, key), floor(root, key)};
		}
};
