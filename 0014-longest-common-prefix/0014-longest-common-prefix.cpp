class Solution {
public:
    class TrieNode {
    public:
        bool isEnd;
        unordered_map<char, TrieNode*> children;
        TrieNode() {
            isEnd = false;
        }
    };
    class Trie {
    public:
        TrieNode* root;
        Trie() {
            root = new TrieNode();
        }
        void insert(string word) {
            int len = word.size();
            TrieNode* cur = root;
            for (char c: word) {
                if (cur->children.find(c) == cur->children.end()) {
                    cur->children[c] = new TrieNode();
                }
                cur = cur->children[c];
            }
            cur->isEnd = true;
        }
        bool search(string word) {
            int len = word.size();
            TrieNode* cur = root;
            for (char c: word) {
                if (cur->children.find(c) == cur->children.end()) {
                    return false;
                }
                cur = cur->children[c];
            }
            return cur->isEnd;
        }
        string longestCommonPrefix(string word) {
            int len = word.size();
            TrieNode* cur = root;
            for (int i = 0; i < len; i++) {
                char c = word[i];
                if (cur->children.find(c) != cur->children.end() && cur->children.size() == 1 && cur->isEnd == false) {
                    cur = cur->children[c];
                } else {
                    return word.substr(0, i);
                }
            }
            return word;
        }
    };
    
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        Trie* trie = new Trie();
        for (int i = 0; i < n; i++) {
            trie->insert(strs[i]);
        }
        return trie->longestCommonPrefix(strs[0]);
    }
};