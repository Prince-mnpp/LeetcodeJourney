class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int n = s.size();

        stack<char> st;
        for(int i=0; i<n; i++){
            if(s[i] == '(') st.push(s[i]);
            if(s[i] == ')'){
                if(st.empty()) open++;
                else{
                    st.pop();
                }
            }
        }
        return open + st.size();
    }
};