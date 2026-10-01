class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        // if(s.size() == 1) return false;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else if(s[i] == ')'){
                if(st.empty()) return false;
                else if(st.top() != '(') return false;
                else st.pop();
            }
            else if(s[i] == '}'){
                if(st.empty()) return false;
                else if(st.top() != '{') return false;
                else st.pop();
            }
            else{
                if(st.empty()) return false;
                else if(st.top() != '[') return false;
                else st.pop();
            }
        }
        return st.size() == 0;
    }
};