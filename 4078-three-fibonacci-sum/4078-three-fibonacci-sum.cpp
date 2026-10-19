class Solution {
public:
    bool threeFibonacciSum(int n) {
        int a = 0;
        int b = 1;
        int c = 0;
        if(n % 2 != 0) return false;

        while(c <= n/2){
            c = a+b;
            if(c == n/2) return true;

            a = b;
            b = c;
        }
        return false;
    }
};