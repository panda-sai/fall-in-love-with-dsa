// Fall in Love With DSA, Example 16.1: A trie with insert, search and startsWith
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// ---- code from the book ----
struct TrieNode {
    TrieNode* child[26] = {};       // all nullptr
    bool isEnd = false;
};

class Trie {
    TrieNode* root = new TrieNode();

  // follow s from the root; nullptr if the path breaks
    TrieNode* walk(const string& s) {
        TrieNode* node = root;
        for (char c : s) {
            node = node->child[c - 'a'];
            if (node == nullptr) return nullptr;
        }
        return node;
    }
public:
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int i = c - 'a';
            if (node->child[i] == nullptr)
                node->child[i] = new TrieNode();
            node = node->child[i];
        }
        node->isEnd = true;
    }
    bool search(const string& word) {
        TrieNode* node = walk(word);
        return node != nullptr && node->isEnd;
    }
    bool startsWith(const string& prefix) {
        return walk(prefix) != nullptr;
    }
};

// ---- a small test, so you can run this example ----
int main() {
    Trie t;
    for (string w : {"do", "dog", "car", "cart", "cat"}) t.insert(w);
    cout << "search car: " << t.search("car") << endl;
    cout << "search ca: " << t.search("ca") << endl;
    cout << "startsWith ca: " << t.startsWith("ca") << endl;
    cout << "startsWith cu: " << t.startsWith("cu") << endl;
}
