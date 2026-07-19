class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> num(26,0);
        vector<int> vis(26, 0);

        for(int i=0; i<s.length(); i++){
            num[s[i]-'a']++;
        }
        string ans = "";

        for(char ch : s){
            if(!vis[ch-'a']){
                while(!ans.empty() && ans.back() > ch){
                    if(num[ans.back() - 'a'] > 0){
                        vis[ans.back() - 'a'] = 0;
                        ans.pop_back();
                    }
                    else {
                        break;
                    }
                }
                vis[ch - 'a'] = 1;
                ans.push_back(ch);
            }
            num[ch-'a'] -= 1;
        }
        return ans;
    }
};