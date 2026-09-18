class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = 0;
        int n = citations.size();
        int r = n-1;
        int m;
        while(l < r){
            m = (l+r)/2;

            if(n - m > citations[m]){
                l = m+1;
            }
            else{
                r = m;
            }
        }
        if(citations[l] >= n-l) return n-l;
        return 0;
    }
};