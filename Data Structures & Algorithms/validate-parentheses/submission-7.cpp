class Solution {
private:
    // unordered_map<char, char> = { '{' : '}', '[':']', '(':')'};

public:
    bool isValid(string s) {
        stack<char> st;
        for(char c: s){
            if(c==']' || c=='}' || c==')'){
                if(st.empty())
                    return false;

                char ct = st.top();
                if((c==']' && ct=='[') || (c==')' && ct=='(') || (c=='}' && ct=='{'))
                    st.pop();
                else
                    return false;
            }
            else{
                st.push(c);
            }
        }    

        return st.empty();
    }
};
