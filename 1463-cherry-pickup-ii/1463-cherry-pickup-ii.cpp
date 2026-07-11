class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m, 0)));

        for(int i=0; i<m; i++){
            for(int j=0; j<m; j++){
                if(i == j){
                    dp[n-1][i][j] = grid[n-1][i];
                }
                else{
                    dp[n-1][i][j] = grid[n-1][i] + grid[n-1][j];
                }
            }
        }

        for(int i=n-2; i>=0; i--){
            for(int j1=0; j1<m; j1++){
                for(int j2=0; j2<m; j2++){
                    int curr = j1 == j2 ? grid[i][j1] : grid[i][j1]+grid[i][j2];
                    int maxi = INT_MIN;

                    for(int d1=-1; d1<=1; d1++){
                        for(int d2=-1; d2<=1; d2++){
                            int newJ1 = j1 + d1;
                            int newJ2 = j2 + d2;

                            if (newJ1 >= 0 && newJ1 < m &&
                                newJ2 >= 0 && newJ2 < m) {
                                maxi = max(maxi, curr + 
                                           dp[i+1][newJ1][newJ2]);
                            } else {
                                maxi = max(maxi, (int)-1e9);
                            }
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        return dp[0][0][m-1];
    }
};