class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c: s){
            if(c=='[' || c=='{' || c=='(')
                st.push(c);
            else{
                if(!st.empty()){
                    char ch = st.top();
                    st.pop();
                    if(!(c==']' && ch=='[') && !(c==')' && ch=='(') && !(c=='}' && ch=='{'))
                        return false;
                }   
                else
                    return false;                 
            }
        }
        return st.empty();
    }
};
