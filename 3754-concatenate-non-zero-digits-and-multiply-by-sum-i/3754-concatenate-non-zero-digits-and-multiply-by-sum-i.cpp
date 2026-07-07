class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long num = 0;

        while(n > 0){
            int curr = n % 10;
            sum += curr;
            if(curr != 0){
                num = num * 10 + curr;
            }
            n/=10;
        }
        int num2 = 0;
        while(num > 0){
            int curr = num % 10;
            num2 = num2 * 10 + curr;
            num/=10;
        }
        return sum * num2;
    }
};