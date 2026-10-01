class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(char c : s)
            if(isalnum(c))
                str+=(char)tolower(c);

        int r = str.size()-1, l=0;
        while(l<=r)
            if(str[l++]!=str[r--])
                return false;

        return true;
    }
};
