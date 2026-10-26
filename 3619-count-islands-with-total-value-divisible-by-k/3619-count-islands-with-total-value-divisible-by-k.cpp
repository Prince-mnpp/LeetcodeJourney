class Solution {
public:
    void dfs(int x, int y, vector<vector<bool>> &vis, vector<vector<int>> &grid, int n, int m, long long &sum){
        vis[x][y] = true;
        sum += grid[x][y];

        int delx[4] = {1,0,-1,0};
        int dely[4] = {0,1,0,-1};

        for(int i=0; i<4; i++){
            int nx = x + delx[i];
            int ny = y + dely[i];

           if(nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == 0) continue;

            if(!vis[nx][ny]){
                dfs(nx, ny, vis, grid, n, m, sum);
            }
        }
    }


    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        int cnt = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]){
                    long long sum = 0;
                    dfs(i,j,vis, grid, n, m, sum);
                    if(sum % k == 0) cnt++;
                }
            }
        }
        return cnt;
    }
};