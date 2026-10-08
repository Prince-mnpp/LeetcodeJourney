class Solution {
public:
    void solve(vector<int>& tail, int key) {
        int l = 0, r = tail.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (tail[mid] >= key)
                r = mid - 1;
            else
                l = mid + 1;
        }

        tail[l] = key;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> tail;

        for (int x : nums) {
            if (tail.empty() || tail.back() < x) {
                tail.push_back(x);
            } 
            else {
                solve(tail, x);
            }
        }

        return tail.size();
    }
};