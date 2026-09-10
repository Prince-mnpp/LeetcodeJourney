class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
       unordered_map<int, int> mp;

       mp[nums[0]] = 1;
       for(int i=1; i<nums.size(); i++){
        if(nums[i] != nums[i-1]){
            mp[nums[i]]++;
        }
       }

       int cnt = 0;

       for(auto v : mp){
        if(v.second == 1) cnt++;
       }
       return cnt;
    }
};