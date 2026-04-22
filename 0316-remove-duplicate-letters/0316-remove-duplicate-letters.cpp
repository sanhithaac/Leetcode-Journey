class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last(26);
        vector<bool> used(26, false);
        
        for(int i = 0; i < s.size(); i++)
            last[s[i] - 'a'] = i;
        
        string res = "";
        
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            
            if(used[c - 'a']) continue;
            
            while(!res.empty() && res.back() > c && last[res.back() - 'a'] > i) {
                used[res.back() - 'a'] = false;
                res.pop_back();
            }
            
            res.push_back(c);
            used[c - 'a'] = true;
        }
        
        return res;
    }
};