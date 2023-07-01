#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

using ll = long long;

void solve() {
    ll n;
    cin >> n;

    ll dimension = pow(2, n);

    ll mtx[dimension][dimension];
    bool vis[dimension][dimension];

    for(ll i = 0; i < dimension; i++) {
        for(ll j = 0; j < dimension; j++) {
            mtx[i][j] = 0;
        }
    }

    for(ll i = 0; i < dimension; i++) {
        for(ll j = 0; j < dimension; j++) {
            vis[i][j] = false;
        }
    }

    for(ll i = 0; i < dimension; i++) {
        for(ll j = 0; j < dimension; j++) {
            cin >> mtx[i][j];
        }
    }

    // Direction vectors
    ll dRow[] = { -1, 0, 1,  0 };
    ll dCol[] = {  0, 1, 0, -1 };

    ll components = 0;
    set<ll> values;

    for(ll r = 0; r < dimension; r++) {
        for(ll s = 0; s < dimension; s++) {
            if(!vis[r][s]) {
                queue<pair<ll, ll>> q;

                q.push({r, s});
                vis[r][s] = true;

                ll value = mtx[r][s];

                if(value < 0 || value > ((pow(4, n) - 1) / 3) || values.count(value)) {
                    cout << 0 << endl;
                    return;
                }

                values.insert(value);

                ll squares = 0;

                while(!q.empty()) {
                    pair<ll, ll> cell = q.front();
                    ll x = cell.first;
                    ll y = cell.second;

                    squares++;

                    q.pop();

                    for(ll i = 0; i < 4; i++) {
                        ll adjx = x + dRow[i];
                        ll adjy = y + dCol[i];

                        if(!(adjx < 0 || adjy < 0 || adjx >= dimension || adjy >= dimension || vis[adjx][adjy] || mtx[adjx][adjy] != value)) {
                            q.push({ adjx, adjy });
                            vis[adjx][adjy] = true;
                        }
                    }
                }

                if((squares == 1 && mtx[r][s] != 0) || (squares != 1 && squares != 3)) {
                    cout << 0 << endl;
                    return;
                }
            }
        }
    }

    cout << 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
