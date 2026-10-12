class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        int l = 0;
        int r = 0;
        int sum = 0;
        int ans = 0;

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