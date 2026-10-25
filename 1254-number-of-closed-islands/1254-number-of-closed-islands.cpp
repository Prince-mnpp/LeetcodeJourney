class Solution {
public:
    void dfs(int x, int y, vector<vector<bool>> &vis, vector<vector<int>> &grid, int n, int m, bool &poss){
        vis[x][y] = true;

        int delx[4] = {1,0,-1,0};
        int dely[4] = {0,1,0,-1};

        for(int i=0; i<4; i++){
            int nx = x + delx[i];
            int ny = y + dely[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if(grid[nx][ny] == 1) continue;
            if(vis[nx][ny]) continue;

            if(grid[nx][ny] == 0 && (nx == 0 || nx == n-1 || ny == 0 || ny == m-1)){
                poss = false;
            }

            if(grid[nx][ny] == 0){
                dfs(nx, ny, vis, grid, n, m, poss);
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        int cnt = 0;

        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                if(!vis[i][j] && grid[i][j] == 0){
                    bool poss = true;
                    dfs(i,j,vis,grid, n, m, poss);
                    if(poss) cnt++;
                }
            }
        }
        return cnt;
    }
};