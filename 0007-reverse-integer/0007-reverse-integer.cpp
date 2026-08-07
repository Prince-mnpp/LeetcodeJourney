class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x != 0){
            int num = x%10;
            if(INT_MAX/10 < ans || INT_MIN/10 > ans) return 0;
            ans = 1LL * (ans*10 + num);
            x /=10;
        }
        return int(ans);
    }
};