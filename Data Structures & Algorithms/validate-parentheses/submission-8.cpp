class Solution {
private:
    unordered_map<char, char> bracs = { {'}', '{'} , {']', '['} , {')', '('}};

public:
    bool isValid(string s) {
        stack<char> st;
        for(char c: s){
            if(c==']' || c=='}' || c==')'){
                if(st.empty() || bracs[c]!=st.top())
                    return false;
                else
                    st.pop();
            }
            else{
                st.push(c);
            }
        }    

        return st.empty();
    }
};
