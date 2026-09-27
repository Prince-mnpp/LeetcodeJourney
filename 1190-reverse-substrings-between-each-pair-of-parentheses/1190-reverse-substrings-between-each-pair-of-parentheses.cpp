class Solution {
public:
    string reverseParentheses(string s) {

        while (true) {

            int r = -1;

            // Find the first ')'
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == ')') {
                    r = i;
                    break;
                }
            }

            if (r == -1)
                break;

            // Find its matching '('
            int l = r - 1;

            while (s[l] != '(') {
                l--;
            }

            string s2 = s.substr(l + 1, r - l - 1);

            reverse(s2.begin(), s2.end());

            s.replace(l, r - l + 1, s2);
        }

        return s;
    }
};