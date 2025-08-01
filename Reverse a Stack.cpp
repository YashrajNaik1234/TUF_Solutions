class Solution {
public:
    void reverse(stack<int>& st, int ele){
        if(st.empty()){
            st.push(ele); return;
        }
        else{
            int x = st.top(); st.pop();
            reverse(st, ele); st.push(x);
        }
    }
    void reverseStack(stack<int> &st) {
        // Your code goes here
        if(!st.empty()){
            int ele = st.top(); st.pop();
            reverseStack(st); reverse(st, ele);
        }
    }
};
