class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> digitSum(n);

        for(int i=0; i<n; i++){
            int sum = 0;
            int k = nums[i];
            while(k > 0){
                int l = k%10;
                sum += l;
                k/=10;
            }
            digitSum[i] = sum;
        }

        vector<int> ind(n);
        iota(ind.begin(), ind.end(), 0);
        sort(ind.begin(), ind.end(), [&](int a, int b){
            if(digitSum[a] != digitSum[b]){
                return digitSum[a] < digitSum[b];
            }
            else {
                return nums[a] < nums[b];
            }
        });

        vector<int> target(n);

        for(int pos=0; pos<n; pos++){
            target[ind[pos]] = pos;
        }

        int c = 0;
        vector<bool> vis(n, false);

        for(int i=0; i<n; i++){
            if(!vis[i]){
                c++;
                int j = i;

                while(!vis[j]){
                    vis[j] = true;
                    j = target[j];
                }
            }
        }
        return n - c;
    }
};