#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

int main() {
    string X, Y;
    cin >> X >> Y;
    int S, R;
    cin >> S >> R;

    int N = X.length();
    int M = Y.length();

    // Preprocess to find all possible substrings of Y and reversed Y
    // that match prefixes of X starting at each position.

    // Since storing all substrings is not feasible, we will build
    // automata for Y and reversed Y and simulate matching.

    // Function to build the automaton (trie) for a string
    auto buildTrie = [](const string& s) {
        vector<map<char, int>> trie(1);
        for (int i = 0; i < s.length(); ++i) {
            int node = 0;
            for (int j = i; j < s.length(); ++j) {
                char c = s[j];
                if (trie[node].count(c) == 0) {
                    trie[node][c] = trie.size();
                    trie.emplace_back();
                }
                node = trie[node][c];
            }
        }
        return trie;
    };

    // Build tries for Y and reversed Y
    auto trieY = buildTrie(Y);
    string revY = Y;
    reverse(revY.begin(), revY.end());
    auto trieRevY = buildTrie(revY);

    vector<int> dp(N + 1, INF);
    vector<int> dpFactor(N + 1, INF);
    dp[0] = 0;
    dpFactor[0] = 0;

    // Simulate matching for Y
    for (int i = 0; i < N; ++i) {
        if (dp[i] == INF) continue;
        // Matching with trieY
        int node = 0;
        for (int j = i; j < N; ++j) {
            char c = X[j];
            if (trieY[node].count(c) == 0) break;
            node = trieY[node][c];
            int substrings = dp[i] + 1;
            int factor = dpFactor[i] + S;
            if (dp[j + 1] > substrings) {
                dp[j + 1] = substrings;
                dpFactor[j + 1] = factor;
            } else if (dp[j + 1] == substrings && dpFactor[j + 1] > factor) {
                dpFactor[j + 1] = factor;
            }
        }
        // Matching with trieRevY
        node = 0;
        for (int j = i; j < N; ++j) {
            char c = X[j];
            if (trieRevY[node].count(c) == 0) break;
            node = trieRevY[node][c];
            int substrings = dp[i] + 1;
            int factor = dpFactor[i] + R;
            if (dp[j + 1] > substrings) {
                dp[j + 1] = substrings;
                dpFactor[j + 1] = factor;
            } else if (dp[j + 1] == substrings && dpFactor[j + 1] > factor) {
                dpFactor[j + 1] = factor;
            }
        }
    }

    if (dp[N] == INF) {
        cout << "Impossible" << endl;
    } else {
        cout << dpFactor[N] << endl;
    }

    return 0;
}
