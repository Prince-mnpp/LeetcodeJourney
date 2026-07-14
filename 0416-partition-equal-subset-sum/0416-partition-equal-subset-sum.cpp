class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        if(sum % 2 != 0){
            return false;
        }
        int target = sum / 2;

        vector<vector<int>> dp(nums.size(), vector<int> (target+1, false));
        for(int i=0; i<nums.size(); i++){
            dp[i][0] = true;
        }
        if(target >= nums[0]){
            dp[0][nums[0]] = true;
        }

        for(int i=1; i<nums.size(); i++){
            for(int j=1; j<=target; j++){
                bool notTaken = dp[i-1][j];
                bool taken = false;
                if(j >= nums[i]){
                    taken = dp[i-1][j-nums[i]];
                }
                dp[i][j] = taken || notTaken;
            }
        }
        return dp[nums.size()-1][target];
    }
};