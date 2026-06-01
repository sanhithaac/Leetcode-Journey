class TrieNode {
public:
    TrieNode* child[26];
    bool end;

    TrieNode() {
        end = false;
        for(int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();

    void insert(string word) {
        TrieNode* node = root;

        for(char c : word) {
            int idx = c - 'a';

            if(node->child[idx] == NULL) {
                node->child[idx] = new TrieNode();
            }

            node = node->child[idx];
        }

        node->end = true;
    }

    bool valid(string word) {
        TrieNode* node = root;

        for(char c : word) {
            node = node->child[c - 'a'];

            if(!node->end) {
                return false;
            }
        }

        return true;
    }

    string longestWord(vector<string>& words) {
        for(string word : words) {
            insert(word);
        }

        string ans = "";

        for(string word : words) {
            if(valid(word)) {
                if(word.size() > ans.size()) {
                    ans = word;
                }
                else if(word.size() == ans.size() && word < ans) {
                    ans = word;
                }
            }
        }

        return ans;
    }
};