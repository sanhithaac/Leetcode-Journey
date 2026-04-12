class Solution {
public:
    bool isPalindrome(string s) {
        string cleaned = "";

        for (char ch : s) {
            if (isalnum(ch)) {
                cleaned += tolower(ch);
            }
        }

        string rev = cleaned;
        reverse(rev.begin(), rev.end());

        return cleaned == rev;
    }
};