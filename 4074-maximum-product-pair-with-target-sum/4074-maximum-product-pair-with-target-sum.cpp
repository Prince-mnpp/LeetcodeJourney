class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int p = INT_MIN;

        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    int prod = nums[i] * nums[j];
                    if(nums[i] == nums[j]) continue;
                    if(p <= prod){
                        p = prod;
                        if(nums[i] > nums[j]){
                            ans[0] = i;
                            ans[1] = j;
                        }
                        else{
                            ans[0] = j;
                            ans[1] = i;
                        }
                    }
                }
            }
        }
        return ans;
    }
};