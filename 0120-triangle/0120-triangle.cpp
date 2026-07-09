class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int sum = 0;
        int n = triangle.size();
        vector<vector<int>> dp(n);
        for(int i=0; i<n; i++){
            dp[i].resize(triangle[i].size());
        }
        dp[0][0] = triangle[0][0];

        for(int i=1; i<n; i++){
            for(int j=0; j<triangle[i].size(); j++){
                if(j > 0 && j < triangle[i-1].size()){
                    dp[i][j] = min(triangle[i][j] + dp[i-1][j], triangle[i][j] + dp[i-1][j-1]);
                }
                else if(j == 0){
                    dp[i][j] = triangle[i][j] + dp[i-1][j];
                }
                else if(j == triangle[i-1].size()){
                    dp[i][j] = triangle[i][j] + dp[i-1][j-1];
                }
            }
        }
        int tot = INT_MAX;
        for(int i=0; i<triangle[n-1].size(); i++){
            if(dp[n-1][i] < tot){
                tot = dp[n-1][i];
            }
        }
        return tot;
    }
};