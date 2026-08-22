class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int ans = -1;
        int minds = INT_MAX;

        for(int i=0; i<drones.size(); i++){
            if((abs(drones[i][0] - target[0]) + abs(drones[i][1]-target[1])) <= drones[i][2]){
                int ds = abs(drones[i][0] - target[0]) + abs(drones[i][1]-target[1]);
                if(ds < minds){
                    ans = i;
                    minds = ds;
                }
            }
        }
        return ans;
    }
};