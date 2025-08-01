class Solution {
public:
    void sortInsert(stack<int>& s, int ele){
    if(s.empty() or ele >= s.top()){
        s.push(ele); return;
    }
    
    int temp = s.top(); s.pop();
    sortInsert(s, ele); s.push(temp);
}
    void sortStack(stack<int> &s) {
        // Your code goes here
        if(!s.empty()){
        int ele = s.top(); s.pop();
        sort(); sortInsert(s, ele);
    }
    }
};
