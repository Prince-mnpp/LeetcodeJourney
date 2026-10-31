class Solution {
public:
    const long long MOD = 1000000007LL;

    long long solve(int i, int j, vector<vector<int>>& grid,
                    int n, int m, int k,
                    vector<vector<vector<long long>>>& dp) {

        if (i >= n || j >= m) return 0;

        if (i == n - 1 && j == m - 1) return 1;

        if (dp[i][j][k] != -1)
            return dp[i][j][k];

        long long cnt = 0;

        if (grid[i][j] == 1) {
            if (k == 1) {
                cnt = solve(i, j + 1, grid, n, m, 0, dp);
            } else {
                cnt = solve(i + 1, j, grid, n, m, 1, dp);
            }
        } else {
            long long down = solve(i + 1, j, grid, n, m, 1, dp);
            long long right = solve(i, j + 1, grid, n, m, 0, dp);

            cnt = (down + right) % MOD;
        }

        return dp[i][j][k] = cnt;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (n == 1 && m == 1) return 1;

        vector<vector<vector<long long>>> dp(
            n, vector<vector<long long>>(
                m, vector<long long>(2, -1)
            )
        );

        long long down = solve(1, 0, grid, n, m, 1, dp);
        long long right = solve(0, 1, grid, n, m, 0, dp);

        return (down + right) % MOD;
    }
};