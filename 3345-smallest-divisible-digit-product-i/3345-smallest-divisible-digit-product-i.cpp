class Solution {
public:
    int smallestNumber(int n, int t) {
        int res = -1;
        for(int i=n; i<=n+9; i++){
            int mul = 1;
            int curr = i;
            while(curr > 0){
                int num = curr%10;
                mul *= num;
                curr = curr / 10;
            }
            if(mul % t == 0){
                res = i;
                break;
            }
        }
        return res;
    }
};