class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        vector<int> p(n + 1, INT_MAX);
        vector<int> s1(n + 1, INT_MAX);

        // Prefix
        int sum = 0;

        for (int l = 0, r = 0; r < n; r++) {
            sum += arr[r];

            while (sum > target) {
                sum -= arr[l++];
            }

            p[r + 1] = p[r];

            if (sum == target) {
                p[r + 1] = min(p[r], r - l + 1);
            }
        }

        // Suffix
        sum = 0;

        for (int r = n - 1, l = n - 1; r >= 0; r--) {
            sum += arr[r];

            while (sum > target) {
                sum -= arr[l--];
            }

            s1[r] = s1[r + 1];

            if (sum == target) {
                s1[r] = min(s1[r], l - r + 1);
            }
        }

        // Combine prefix and suffix
        int ans = INT_MAX;

        for (int i = 0; i <= n; i++) {
            if (p[i] != INT_MAX && s1[i] != INT_MAX) {
                ans = min(ans, p[i] + s1[i]);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};