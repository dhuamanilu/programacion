#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;

#define dbg(x) cout << #x << ": " << x << endl;

void solve() {
    // <>
    int n; cin >> n;
    
    vector<pair<string, ll>> input;

    map<ll, ll> hist;
    for(int i = 0; i <  n; i++) {
        string S; cin >> S;
        ll P; cin >> P;
        vl E(6); for(auto& x: E) cin >> x;
        sort(E.begin(), E.end());

        ll score = P * 10LL;
        for(auto& x: E) score += x;
        score -= E.front();
        score -= E.back();

        hist[score]++;
        
        input.emplace_back(S, score);
       
        //dbg(i);
        //dbg(score); 
    } 

    vl scores;
    for(auto& [val, _]: hist) {
        scores.emplace_back(val);
    }
    reverse(scores.begin(), scores.end());

    ll lst = 0;
    vl target_scores;
    ll tot = 0;
    for(int i = 0; i < int(scores.size()); i++) {
        if(lst > 2 || (tot + hist[scores[i]] > 1000LL)) {
            break;
        }
        lst += hist[scores[i]];
        tot += hist[scores[i]];
        target_scores.emplace_back(scores[i]);
    }

    set<int> aux;
    for(auto& x: target_scores) aux.emplace(x);

    map<ll, vl> G;
    for(int i = 0; i < n; i++) {
        auto [teamname, score] = input[i];
        if(aux.count(score)) {
            G[score].emplace_back(i);
        }
    }

    for(auto& score: target_scores) {
        for(auto& id: G[score]) {
            auto [teamname, sco] = input[id];
            cout << teamname << " " << sco << "\n"; 
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
   
    solve();

    return 0;
}
