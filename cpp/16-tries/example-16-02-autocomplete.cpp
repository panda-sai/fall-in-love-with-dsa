// Fall in Love With DSA, Example 16.2: Autocomplete
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

// ---- helpers used by the test below (not printed in the book) ----
struct TrieNode {
    TrieNode* child[26] = {};
    bool isEnd = false;
};
void add(TrieNode* r, string w) {
    for (char c : w) {
        if (!r->child[c - 'a']) r->child[c - 'a'] = new TrieNode();
        r = r->child[c - 'a'];
    }
    r->isEnd = true;
}

// ---- code from the book ----
void collect(TrieNode* node, string& word,
             vector<string>& out) {
    if (node->isEnd) out.push_back(word);
    for (int i = 0; i < 26; i++) {
        if (node->child[i] != nullptr) {
            word.push_back('a' + i);       // go down
            collect(node->child[i], word, out);
            word.pop_back();               // come back
        }
    }
}

vector<string> suggest(TrieNode* root,
                       const string& prefix) {
    TrieNode* node = root;
    for (char c : prefix) {
        node = node->child[c - 'a'];
        if (node == nullptr) return {};    // no matches
    }
    vector<string> out;
    string word = prefix;
    collect(node, word, out);
    return out;
}

// ---- a small test, so you can run this example ----
int main() {
    TrieNode* r = new TrieNode();
    for (string w : {"do", "dog", "car", "cart", "cat"}) add(r, w);
    for (string p : {"ca", "do", "x"}) {
        cout << p << ":";
        for (auto& w : suggest(r, p)) cout << " " << w;
        cout << endl;
    }
}
