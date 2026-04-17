class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.size() < p.size()) return result;

        vector<int> freq(26, 0);

        for (char c : p) {
            freq[c - 'a']++;
        }

        int left = 0, right = 0, count = p.size();

        while (right < s.size()) {
          
            if (freq[s[right] - 'a'] > 0) {
                count--;
            }
            freq[s[right] - 'a']--;
            right++;

            if (count == 0) {
                result.push_back(left);
            }

            if (right - left == p.size()) {
                if (freq[s[left] - 'a'] >= 0) {
                    count++;
                }
                freq[s[left] - 'a']++;
                left++;
            }
        }

        return result;
    }
};