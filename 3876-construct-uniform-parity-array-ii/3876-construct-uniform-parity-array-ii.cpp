class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int alleven = true;
        for(int i=0; i<n; i++){
            if(nums1[i] % 2 != 0){
                alleven = false;
            }
        }
        if(alleven) return true;

        int odd = INT_MAX;
        for(int i=0; i<n; i++){
            if(nums1[i] % 2 != 0){
                odd = min(odd, nums1[i]);
            }
        }
        for(int i=0; i<n; i++){
            if(nums1[i] % 2 == 0){
                if(nums1[i] < odd) return false;
            }
        }
        return true;
    }
};