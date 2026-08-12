class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int l = 0;
        int r = 0;
        int ans = 0;

        while(r < n){
            mp[nums[r]]++;
            if(mp[nums[r]] > k){
                while(mp[nums[r]] > k){
                    mp[nums[l]]--;
                    l++;
                }
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};