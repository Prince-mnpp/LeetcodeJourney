class Solution {
public:
    string removeOuterParentheses(string s) {
        int valid = 0;
        string res = "";

        for(char c : s){
            if((c == '(' && valid++) || (c == ')' && --valid)){
                res += c;
            }
        }
        return res;
    }
};