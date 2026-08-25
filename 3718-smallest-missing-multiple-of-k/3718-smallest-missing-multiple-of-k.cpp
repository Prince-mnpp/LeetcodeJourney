class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int x = 1;
        int ans = k;
        int n = nums.size();
        while(true){
            int num = x*k;
            bool found = false;
            for(int i=0; i<n; i++){
                if(nums[i] == num){
                    found = true;
                }
            }
            if(!found){
                ans = num;
                break;
            }
            x++;
        }   
        return ans;
    }
};