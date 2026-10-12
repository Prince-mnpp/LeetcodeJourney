class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        long long l = 0;
        long long r = 0;
        long long sum = 0;
        long long ans = 0;

        while(l <= r && r < n){
            if(nums[r] % k == nums[l] % k){
                sum += nums[r];

                if((sum - nums[r]) % k == 0){
                    ans = max(ans, r-l+1);
                }
                r++;
            }
            else{
                l = r;
                sum = 0;
            }
        }
        return ans;
    }
};