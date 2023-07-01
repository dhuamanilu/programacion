#include <iostream>
#include <cstddef>
#include <string>

using namespace std;

using ll = long long;

pair<ll, ll> getNums(string record) {
    size_t separatorIndex;

    for(int i = 0; i < record.size(); i++) {
        if(record[i] == '-') {
            separatorIndex = i;
        }
    }

    return {
        stoi(record.substr(0, separatorIndex)),
        stoi(record.substr(separatorIndex + 1, record.size() - separatorIndex))
    };
}

void solve() {
    size_t n;
    cin >> n;

    if(n == 1) {
        cout << "ok" << endl;
        return;
    }

    string ss[n];

    for(size_t i = 0; i < n; i++) {
        cin >> ss[i];
    }

    bool finished = false;
    ll inmutableFirst;
    ll inmutableSecond;

    for(int i = 0; i < n - 1; i++) {
        const string currentStr = ss[i];
        const string nextStr = ss[i + 1];

        pair<ll, ll> current = getNums(currentStr);
        pair<ll, ll> next    = getNums(nextStr);

        ll a1 = current.first, a2 = current.second,
           b1 = next.first,    b2 = next.second;

        if(finished) {
            if(b1 != inmutableFirst || b2 != inmutableSecond) {
                cout << "error " << (i + 2) << endl;
                return;
            }
            continue;
        }

        if(a1 == 11 && a2 == 11) {
            cout << "error " << (i + 1) << endl;
            return;
        } else if(a1 == 11 || a2 == 11) {
            inmutableFirst = a1;
            inmutableSecond = a2;
            finished = true;
        }

        if(finished) {
            if(b1 != inmutableFirst || b2 != inmutableSecond) {
                cout << "error " << (i + 2) << endl;
                return;
            }
            continue;
        }

        if(!(
                (a1 == b1 && a2 == b2) ||
                (a1 + 1 == b1 && a2 == b2) ||
                (a2 + 1 == b1 && a1 == b2)
            )) {
            cout << "error " << (i + 2) << endl;
            return;
        }
    }

    cout << "ok" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
