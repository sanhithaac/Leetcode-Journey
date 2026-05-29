class WordDictionary {
public:

    struct Node {
        Node* links[26];
        bool flag = false;

        bool containsKey(char ch) {
            return links[ch - 'a'] != NULL;
        }

        void put(char ch, Node* node) {
            links[ch - 'a'] = node;
        }

        Node* get(char ch) {
            return links[ch - 'a'];
        }

        void setEnd() {
            flag = true;
        }

        bool isEnd() {
            return flag;
        }
    };

    Node* root;

    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;

        for(char ch : word) {
            if(!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }

        node->setEnd();
    }

    bool solve(string word, int index, Node* node) {
        
        if(index == word.size()) {
            return node->isEnd();
        }

        if(word[index] == '.') {

            for(int i = 0; i < 26; i++) {
                if(node->links[i] != NULL) {
                    if(solve(word, index + 1, node->links[i])) {
                        return true;
                    }
                }
            }

            return false;
        }

        if(!node->containsKey(word[index])) {
            return false;
        }

        return solve(word, index + 1, node->get(word[index]));
    }
    
    bool search(string word) {
        return solve(word, 0, root);
    }
};