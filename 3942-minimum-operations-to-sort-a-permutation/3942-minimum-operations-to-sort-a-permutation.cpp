class Solution {
public:
    int solve(vector<int> &nums){
        vector<int> v = nums;
        int n = nums.size();

        for(int x : nums){
            v.push_back(x);
        }

        //increasing check
        int cnt = 1;
        for(int i=1; i<v.size(); i++){
            if(v[i] >= v[i-1]){
                cnt++;

                if(cnt == n){
                    return (i+1 - n);
                }
            }
            else {
                cnt = 1;
            }

            
        }
        cnt = 1;

        for(int i=1; i<v.size(); i++){
            if(v[i] <= v[i-1]){
                cnt++;

                if(cnt == n){
                    return (i+2 - n);
                }
            }
            else {
                cnt = 1;
            }

            
        }
        return 1e9;
    }

    int minOperations(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int ans = solve(nums);

        reverse(nums.begin(), nums.end());
        ans = min(ans, solve(nums)+1);
        return ans == 1e9 ? -1 : ans;
    }
};