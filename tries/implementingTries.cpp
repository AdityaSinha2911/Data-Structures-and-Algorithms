#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, TrieNode* node) {
        links[ch - 'a'] = node;
    }

    TrieNode* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }
    

    bool isEnd() {
        return flag;
    }

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            links[i] = NULL;
        }
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;

        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new TrieNode());
            }

            node = node->get(word[i]);
        }

        node->setEnd();
    }

    bool search(string word) {
        TrieNode* node = root;

        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                return false;
            }

            node = node->get(word[i]);
        }

        return node->isEnd();
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;

        for (int i = 0; i < prefix.size(); i++) {
            if (!node->containsKey(prefix[i])) {
                return false;
            }

            node = node->get(prefix[i]);
        }

        return true;
    }
};
 

int main() {
    Trie trie;

    trie.insert("apple");
    cout << boolalpha << trie.search("apple") << endl;   // Output: true
    cout << boolalpha << trie.search("app") << endl;     // Output: false
    cout << boolalpha << trie.startsWith("app") << endl; // Output: true

    trie.insert("app");
    cout << boolalpha << trie.search("app") << endl;     // Output: true

    return 0;
}