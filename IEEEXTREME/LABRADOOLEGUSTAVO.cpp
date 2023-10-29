#include <bits/stdc++.h>
using namespace std;

const int MAX_LENGTH = 55; // Maximum word length

bool isPrefix(const string& word, const string& prefix) {
    return word.compare(0, prefix.length(), prefix) == 0;
}

bool isSuffix(const string& word, const string& suffix) {
    int wordLength = word.length();
    int suffixLength = suffix.length();
    return word.compare(wordLength - suffixLength, suffixLength, suffix) == 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    unordered_map<string, vector<string>> prefixes;
    unordered_map<string, vector<string>> suffixes;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (s.length() >= 3) {
            prefixes[s.substr(0, 3)].push_back(s);
            suffixes[s.substr(s.length() - 3)].push_back(s);
        }
    }

    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        int len = s.length();
        bool found = false;
        string prefix, suffix;

        for (int j = 1; j < len - 1; ++j) {
            if (j >= 4 && isPrefix(s, s.substr(0, j))) {
                string rest = s.substr(j);
                if (!prefixes[rest].empty()) {
                    prefix = s.substr(0, j);
                    suffix = rest;
                    found = true;
                    break;
                }
            }

            if (j < len - 3 && isSuffix(s, s.substr(j))) {
                string rest = s.substr(0, j);
                if (!suffixes[rest].empty()) {
                    prefix = rest;
                    suffix = s.substr(j);
                    found = true;
                    break;
                }
            }
        }

        if (found) {
            if (prefixes[prefix].size() == 1 && suffixes[suffix].size() == 1) {
                cout << prefixes[prefix][0] << " " << suffixes[suffix][0] << endl;
            } else {
                cout << "ambiguous" << endl;
            }
        } else {
            cout << "none" << endl;
        }
    }

    return 0;
}
