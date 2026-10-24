
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        vector<int> v = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        vector<int> pref(13, 0);

        for (int i = 1; i < v.size(); i++) {
            pref[i] = v[i] + pref[i - 1];
        }

        auto convert = [&](string s) {
            int month = stoi(s.substr(0, 2));
            int day = stoi(s.substr(3, 2));
            return pref[month - 1] + day;
        };

        int start = convert(arriveAlice);
        int end = convert(leaveAlice);
        int start1 = convert(arriveBob);
        int end1 = convert(leaveBob);

        int left = max(start, start1);
        int right = min(end, end1);

        return max(0, right - left + 1);
    }
};
