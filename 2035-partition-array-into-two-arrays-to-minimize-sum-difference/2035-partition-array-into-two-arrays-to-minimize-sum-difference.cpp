#include<algorithm>
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2;
        vector<int> left(nums.begin(), nums.begin()+n);
        vector<int> right(nums.begin()+n, nums.end());

        vector<vector<int>> leftSum(n+1),rightSum(n+1);

        for(int mask=0; mask<(1 << n); mask++){
            int sum = 0;
            int cnt = 0;
            for(int i=0; i<n; i++){
                if(mask & (1 << i)){
                    sum += left[i];
                    cnt++;
                }
            }
            leftSum[cnt].push_back(sum);
        }
        for(int mask=0; mask<(1 << n); mask++){
            int sum = 0;
            int cnt = 0;
            for(int i=0; i<n; i++){
                if(mask & (1 << i)){
                    sum += right[i];
                    cnt++;
                }
            }
            rightSum[cnt].push_back(sum);
        }

        for(int i=0; i<n+1; i++){
            sort(rightSum[i].begin(), rightSum[i].end());
        }

        int total = accumulate(nums.begin(), nums.end(), 0);
        int ans = INT_MAX;

        for(int i=0; i<n+1; i++){
            int rightCnt = n-i;
            for(int leftVal : leftSum[i]){
                int target = total/2 - leftVal;

                auto &v = rightSum[rightCnt];

                auto it = lower_bound(v.begin(), v.end(), target);

                if (it != v.end()) {
                    int s1 = leftVal + *it;
                    ans = min(ans, abs(total - 2 * s1));
                }

                if (it != v.begin()) {
                    --it;
                    int s1 = leftVal + *it;
                    ans = min(ans, abs(total - 2 * s1));
                }
            }
        }
        return ans;
    }
};