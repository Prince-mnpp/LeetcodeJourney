class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string s = "";
        for(int i=0; i<n; i++){
            if(i == 0){
                s += ".";
            }
            else{
                s += "#";
            }
        }
        string s1 = "";
        for(int i=0; i<n; i++){
            s1 += ".";
        }
        vector<string> ans;

        for(int i=0; i<m-1; i++){
            ans.push_back(s);
        }
        ans.push_back(s1);

        return ans;
    }
};