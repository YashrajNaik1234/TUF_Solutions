class Solution {
public:
    string prefixToInfix(string exp) {
        // Your code goes here
        stack <string> st;
        
        for(int i(exp.size() - 1);i >= 0;i--){
            if(isalnum(exp[i])) st.push(string(1, exp[i]));
            else{
                string a = st.top(); st.pop();
                string b = st.top(); st.pop();
                string c = '('+ a + exp[i] + b + ')';
                st.push(c);
            }
        }
        
        return st.top();
    }
};
