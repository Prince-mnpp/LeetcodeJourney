class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    bool dfs(int r, int c, int pr, int pc,
             vector<vector<char>>& grid,
             vector<vector<bool>>& vis) {

        vis[r][c] = true;

        int m = grid.size();
        int n = grid[0].size();

        for (int k = 0; k < 4; k++) {

            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;

            // Different character -> ignore
            if (grid[nr][nc] != grid[r][c])
                continue;

            // Not visited yet
            if (!vis[nr][nc]) {
                if (dfs(nr, nc, r, c, grid, vis))
                    return true;
            }
            // Already visited and not the parent
            else if (nr != pr || nc != pc) {
                return true;
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (!vis[i][j]) {
                    if (dfs(i, j, -1, -1, grid, vis))
                        return true;
                }
            }
        }

        return false;
    }
};