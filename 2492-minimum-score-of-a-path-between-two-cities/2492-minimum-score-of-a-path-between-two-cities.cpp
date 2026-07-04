class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> vis(n+1, 0);
        vector<vector<pair<int,int>>> adj(n+1);

        for(int i=0; i<roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        queue<int> q;
        q.push(1);
        vis[1] = 1;
        int ans = INT_MAX;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(auto &[v,w] : adj[u]){
                ans = min(ans, w);
                if(vis[v] != 1){
                    vis[v] = 1;
                    q.push(v);
                }
                
            }
        }
        return ans;
    }
};