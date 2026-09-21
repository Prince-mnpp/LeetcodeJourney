class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long> (k, 0));

        for(long long i=0; i<n; i++){
            long long x = nums[i] % k;
            dp[i][x] += 1;
            if(i> 0){
                for(long long r=0; r<k; r++){
                long long x = (r * nums[i]) % k;
                dp[i][x] += dp[i-1][r];
            }
            }
            
        }

        vector<long long> res;
        for(long long r = 0; r<k; r++){
            long long ans = 0;
            for(long long i=0; i<n; i++){
                ans += dp[i][r];
            }
            res.push_back(ans);
        }
        return res;
    }
};