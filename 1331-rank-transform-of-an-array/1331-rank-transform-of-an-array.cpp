class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> s;

        for (int x : arr)
            s.insert(x);

        unordered_map<int, int> rankMap;
        int rank = 1;

        while (!s.empty()) {
            int x = *s.begin();
            rankMap[x] = rank++;
            s.erase(s.begin());
        }

        vector<int> ans;

        for (int x : arr)
            ans.push_back(rankMap[x]);

        return ans;
    }
};