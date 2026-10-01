class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
     int n = nums.size();

        map<int, int> mp;

        for(int i=0; i<n;i++){
            mp[nums[i]]++;
        }   
        int m = mp.size();

        vector<int> dp(m, 0);
        vector<int> values;
        vector<int> points;
        for(auto &it: mp)
        {
            values.push_back(it.first);
            points.push_back(it.first * it.second);
        }
        dp[0] = points[0];

        for(int i=1; i<m; i++){
            if(values[i] == values[i-1] + 1){
                dp[i] = max(dp[i-1], points[i] + (i>=2 ? dp[i-2] : 0));
            }
            else{
                dp[i] = dp[i-1] + points[i];
            }
        }
        return dp[m-1];
    }
};