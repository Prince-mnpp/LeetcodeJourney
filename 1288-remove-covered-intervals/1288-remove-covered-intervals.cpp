class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int cnt = n;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(j != i){
                    if(intervals[i][0] >= intervals[j][0] && intervals[i][1] <= intervals[j][1]){
                        cnt--; 
                        break;
                    }
                }
            }
        }
        return cnt;
    }
};