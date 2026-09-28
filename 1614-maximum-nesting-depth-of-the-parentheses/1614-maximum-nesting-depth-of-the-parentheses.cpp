class Solution {
public:
    int maxDepth(string s) {
        int ans = INT_MIN;
        int open = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                open++;
                ans = max(ans, open);
            }
            else if(s[i] == ')'){
                open--;
            }
        }
        if(ans == INT_MIN) return 0;
        return ans;
    }
};