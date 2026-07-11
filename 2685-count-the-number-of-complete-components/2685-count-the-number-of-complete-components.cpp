class Solution {
public:
    void count(int u, vector<vector<int>> &adj, vector<bool> &vis, int &n, int &m){
        vis[u] = true;
        n++;
        m += adj[u].size();

        for(int v : adj[u]){
            if(!vis[v]){
                count(v, adj, vis, n, m);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);

        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = 0;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                int n = 0;
                int m = 0;
                count(i, adj, vis, n, m);

                int e = m/2;
                if(e == n*(n-1)/2){
                    ans++;
                }
            }
        }
        return ans;
    }
};