class Solution {
public:
    int countPrimes(int n) {
        vector<int> isPrime(n, 0);
        int cnt = 0;

        for(int i=2; i<n; i++){
            if(isPrime[i] == 0) cnt++;

            for(int j=i*2; j<n; j=j+i){
                isPrime[j] = 1;
            }
        }
        return cnt;
    }
};