class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        vector<bool> v(n+1, true);
        v[0] = v[1] = false;

        for(long long i=2; i<=n; i++){
            if(v[i]){
                for(long long j=i*i; j<=n; j += i){
                    v[j] = false;
                }
            }
        } 
        vector<int> prime;
        for(long long i=2; i<=n; i++){
            if(v[i]){
                prime.push_back(i);
            } 
        }

        long long r = 0;

        long long sum = 0;

        vector<int> ans;

        while(sum < s && r < prime.size()){
            sum += prime[r];
            if(sum <= s) ans.push_back(prime[r]);
            r++;
        }

        return ans;
    }

};