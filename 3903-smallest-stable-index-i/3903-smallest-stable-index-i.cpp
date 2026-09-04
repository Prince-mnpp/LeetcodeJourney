class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> l(n);
        vector<int> s(n);

        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int i=0; i<n; i++){
            maxi = max(maxi, nums[i]);
            l[i] = maxi;
        }

        for(int i=n-1; i>=0; i--){
            mini = min(mini, nums[i]);
            s[i] = mini;
        }
        for(int i=0; i<n; i++){
            int st = l[i] - s[i];
            if(st <= k) return i;
        }
        return -1;
    }
};