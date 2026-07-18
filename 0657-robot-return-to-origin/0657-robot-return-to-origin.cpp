class Solution {
public:
    bool judgeCircle(string moves) {
        vector<int> dir(4, 0);
        for(int i=0; i<moves.length(); i++){
            if(moves[i] == 'U') dir[0]++;
            else if(moves[i] == 'D') dir[1]++;
            else if(moves[i] == 'L') dir[2]++;
            else{
                dir[3]++;
            }
        }
        int sum = 0;
        sum += abs(dir[0] - dir[1]);
        sum += abs(dir[2] - dir[3]);

        return sum==0;
    }
};