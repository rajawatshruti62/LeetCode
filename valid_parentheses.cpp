class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        if(s[0]==')' || s[0]==']' || s[0]=='}')
        return false;
        for(auto i:s){
            if(i=='(' || i=='[' || i=='{')
            st.push(i);
            else if(! st.empty() && ((st.top() == '(' && i == ')' ) || 
                (st.top() == '{' && i == '}'  ) ||   
                (st.top() == '[' && i == ']')))
                st.pop();
            else
                return false;
           
        }
        return st.empty();
    }
};
