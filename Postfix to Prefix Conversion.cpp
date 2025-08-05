class Solution {
public:
    string postToPre(string exp) {
        // Your code goes here
        stack <string> st;
        
        for(int i(0);i < exp.size();i++){
            if(isalnum(exp[i])) st.push(string(1, exp[i]));
            else{
                string a = st.top(); st.pop();
                string b = st.top(); st.pop();
                st.push(exp[i] + b + a);
            }
        }
        
        return st.top();
    }
};
