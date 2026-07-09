class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> adj(graph.size());
        vector<int> indegree(graph.size(),0);

        for(int i=0; i<graph.size(); i++){
            for(int it : graph[i]){
                adj[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0; i<graph.size(); i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> safe;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            safe.push_back(u);
            for(int v : adj[u]){
                indegree[v] --;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        sort(safe.begin(), safe.end());
        return safe;
    }
};