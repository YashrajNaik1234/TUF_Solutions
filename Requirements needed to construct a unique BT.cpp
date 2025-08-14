class Solution{	
	public:	
		bool uniqueBinaryTree(int a, int b){
			//your code goes here
            if((a == 2 or b == 2 ) and (a != 2 or b != b)) return true;
            return false;
		}
};
