class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(!(nums[i] ^ nums[j])){
                    ans = ans ^ nums[i];
                    continue;
                }
            }
        }
        return ans;
    }
};