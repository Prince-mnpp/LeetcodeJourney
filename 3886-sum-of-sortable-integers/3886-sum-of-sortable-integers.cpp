class Solution {
public:
    vector<int> check(vector<int>& nums, int l, int r,
                      int currMax) {
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (int i = l; i < r; i++) {
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }

        // Current block must not overlap the previous
        // block's sorted range.
        if (mini < currMax) {
            return {0, maxi};
        }

        // Count descents, including the circular boundary.
        int descents = 0;

        for (int i = l; i < r; i++) {
            int next = (i + 1 < r) ? i + 1 : l;

            if (nums[i] > nums[next]) {
                descents++;
            }
        }

        if (descents > 1) {
            return {0, maxi};
        }

        return {1, maxi};
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            int maxi = INT_MIN;
            bool sortable = true;

            for (int j = 0; j < n; j += k) {
                vector<int> v = check(nums, j, j + k, maxi);

                if (!v[0]) {
                    sortable = false;
                    break;
                }

                maxi = v[1];
            }

            if (sortable) {
                ans += k;
            }
        }

        return ans;
    }
};