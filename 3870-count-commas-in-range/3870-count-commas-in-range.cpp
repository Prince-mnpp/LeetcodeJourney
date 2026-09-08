class Solution {
public:
    int countCommas(int n) {
        if(n < 1000) return 0;

        if(n == 100000){
            int cnt = 99999 - 1000 + 1;
            return cnt + 1;
        }
        return n - 1000 + 1;
    }
};