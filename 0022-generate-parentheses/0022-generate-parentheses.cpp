class Solution {
public:
    void helper(vector<string> &ans, string s, int open, int close, int &n){
        if(open > n) return;
        else if(close > open) return;
        else if(open == n && close == n){
            ans.push_back(s);
            return;
        }

        helper(ans, s + "(", open+1, close, n);
        helper(ans, s + ")", open, close+1, n);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(ans, "", 0, 0, n);
        return ans;
    }
};