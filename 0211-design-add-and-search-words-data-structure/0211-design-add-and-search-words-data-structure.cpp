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

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
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

    bool dfs(string& word, int pos, TrieNode* node) {
        if(node == NULL) return false;

        if(pos == word.size()) {
            return node->end;
        }

        if(word[pos] == '.') {
            for(int i = 0; i < 26; i++) {
                if(dfs(word, pos + 1, node->child[i])) {
                    return true;
                }
            }
            return false;
        }

        return dfs(word, pos + 1, node->child[word[pos] - 'a']);
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};