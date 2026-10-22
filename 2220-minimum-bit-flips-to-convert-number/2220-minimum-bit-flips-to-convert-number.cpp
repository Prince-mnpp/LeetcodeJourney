class Solution {
public:
    int minBitFlips(int start, int goal) {
     int n = start ^ goal;
     int cnt = 0;
        while(n > 0){
            cnt += n%2;

            n/=2;
        }   
        return cnt;
    }
};