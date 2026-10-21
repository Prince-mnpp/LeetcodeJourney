class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0) return false;
        long long n1 = n;
        return ((n1 & n1-1) == 0);
    }
};