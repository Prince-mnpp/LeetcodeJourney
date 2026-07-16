class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> mx;
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            maxi = max(maxi, nums[i]);
            mx.push_back(maxi);
        }
        vector<int> prefixGCD;
        for(int i=0; i<n; i++){
            int ans = gcd(nums[i], mx[i]);
            prefixGCD.push_back(ans);
        }
        sort(prefixGCD.begin(), prefixGCD.end());
        int l = 0;
        int r = n-1;
        vector<int> res;
        while(l < r){
            int ans = gcd(prefixGCD[l], prefixGCD[r]);
            res.push_back(ans);
            l++;
            r--;
        }
        long long sum = 0;
        for(int i=0; i<res.size(); i++){
            sum += res[i];
        }
        return sum;
    }
};