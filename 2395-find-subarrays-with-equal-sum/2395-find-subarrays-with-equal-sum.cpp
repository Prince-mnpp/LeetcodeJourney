class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n,0);

        for(int i=1; i<n; i++){
            p[i] = nums[i] + nums[i-1];
        } 
        for(int i=1; i<n; i++){
            int x = p[i];
            for(int j=1; j<n && j!=i; j++){
                if(p[j] == x) return true;
            }
        }
        return false;
    }
};