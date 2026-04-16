class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        int maxFreq = 0, maxChar = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
                maxChar = i;
            }
        }

        if (maxFreq > (s.size() + 1) / 2) return "";

        string res(s.size(), ' ');
        int idx = 0;

        while (freq[maxChar]--) {
            res[idx] = maxChar + 'a';
            idx += 2;
        }

        for (int i = 0; i < 26; i++) {
            while (freq[i] > 0) {
                if (idx >= s.size()) idx = 1;
                res[idx] = i + 'a';
                idx += 2;
                freq[i]--;
            }
        }

        return res;
    }
};