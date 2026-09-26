class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }
        int soln = 0;

        for(auto &it : mp){
            bool flag = true;
            if(it.second.size() < 3){
                continue;
            }
            int d1 = it.second[1] - it.second[0];
            for(int i=2; i<it.second.size(); i++){
                if(it.second[i] - it.second[i-1] != d1){
                    flag = false;
                }
            }
            if(flag){
                soln++;
            }
        }
        return soln;
    }
};