class Solution {
public:
    unordered_map<string, string> mp;

    string encode(string longUrl) {
        string shortUrl = to_string(mp.size());
        mp[shortUrl] = longUrl;
        return shortUrl;
    }

    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};