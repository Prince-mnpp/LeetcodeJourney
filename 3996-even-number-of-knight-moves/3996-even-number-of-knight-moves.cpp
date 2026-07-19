class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        // queue<pair<pair<int,int>,int>> q;
        // q.push({{start[0],start[1]},0});

        // vector<vector<int>> vis(8, vector<int> (8, 0));
        // vis[start[0]][start[1]] = 1;

        // while(!q.empty()){
        //     int r = q.front().first.first;
        //     int c = q.front().first.second;
        //     int steps = q.front().second;
        //     q.pop();
        //     if(r == target[0] && c == target[1] && steps%2 == 0) return true;

        //     int dirr[8] = {-2,-2,-1,-1,1,1,2,2};
        //     int dirc[8] = {1,-1,2,-2,2,-2,1,-1};

        //     for(int i=0; i<8; i++){
        //         int nrow = r + dirr[i];
        //         int ncol = c + dirc[i];

        //         if(nrow >=0 && nrow < 8 && ncol >= 0 && ncol < 8 && !vis[nrow][ncol]){
        //             q.push({{nrow,ncol},steps+1});
        //             vis[nrow][ncol] = 1;
        //         }
        //     }
        // }
        // return false;
        return (start[0]+start[1])%2 == (target[0]+target[1])%2;
        }
};