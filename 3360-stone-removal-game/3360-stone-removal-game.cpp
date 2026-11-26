class Solution {
public:
    bool canAliceWin(int n) {
        int i = 10;

        while(true){
            if(n < i) return false;

            n -= i;

            if(n < i-1) return true;

            n -= (i-1);

            i = i-2;
        }
        return false;
    }
};