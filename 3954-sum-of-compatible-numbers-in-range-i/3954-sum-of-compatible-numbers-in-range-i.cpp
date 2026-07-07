class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {

        int low = max(1, n - k);
        int high = n + k;

        int sum = 0;

        for (int x = low; x <= high; x++) {

            if ((n & x) == 0) {
                sum += x;
            }
        }

        return sum;
    }
};