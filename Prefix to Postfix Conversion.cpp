class Solution {
public:
    string prefixToPostfix(const string& s) {
        // Your code goes here
        stack <string> st;
        string exp = s;
        
        for(int i(exp.size() - 1);i >= 0;i--){
            if(isalnum(exp[i])) st.push(string(1, exp[i]));
            else{
                string a = st.top(); st.pop();
                string b = st.top(); st.pop();
                st.push(a + b + exp[i]);
            }
        }
        
        return st.top();
    }
};
