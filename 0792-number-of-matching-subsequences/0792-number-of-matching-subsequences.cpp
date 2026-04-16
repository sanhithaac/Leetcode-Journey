class Solution {
public:
    bool check(string &s, string &w) {
        int i = 0, j = 0;
        while (i < s.size() && j < w.size()) {
            if (s[i] == w[j]) j++;
            i++;
        }
        return j == w.size();
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string, bool> mp;
        int count = 0;

        for (string &w : words) {
            if (mp.find(w) == mp.end()) {
                mp[w] = check(s, w);
            }
            if (mp[w]) count++;
        }

        return count;
    }
};