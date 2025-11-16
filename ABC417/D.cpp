#pragma GCC optimize ("Ofast")
//? #pragma GCC target ("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

//* Debugger
string to_string(string s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

template <typename A>
string to_string(A v);

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "[";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "]";
    return res;
}
//* /Debugger

using ll = long long;
using pl = pair<ll, ll>;

#define tcT template<class T
tcT> using V = vector<T>;
using vl = V<ll>;

#define sz(x) int((x).size())
#define all(x) bg(x), end(x)

#define dbg(x) cout << "Line(" << __LINE__ << "): " << "\033[1;34m" << #x << "\033[0;32m = \033[35m" << to_string(x) << "\033[0m" << endl;
#define GA dbg(0)
#define RAYA   dbg("================================");

void setIn(string s) { freopen(s.c_str(), "r", stdin); }

void solve(){
    ll n;
    cin>>n;
    V<array<ll,3>> info(n);
    ll maxi = 0;
    for(auto & e : info){
        cin>>e[0]>>e[1]>>e[2];
        maxi=max(maxi,e[0]+e[1]);
    }
    V<vl> dp(n,vl(maxi+1));
    for(ll j=0;j<=maxi;j++){
        dp[n-1][j] = (j<= info[n-1][0]  ? j + info[n-1][1] : max(0ll,j-info[n-1][2]));
    }
    for(ll i=n-2;i>=0;i--){
        for(ll j=0;j<=maxi;j++){
            dp[i][j] = (j <= info[i][0]  ?  dp[i+1][j + info[i][1]] : dp[i+1][max(0ll,j - info[i][2])]);
        }
    }
    vl pref(n,0);
    pref[0]=info[0][2];
    for(ll i=1;i<n;i++){
        pref[i]=pref[i-1] + info[i][2];
    }
    ll q;
    cin>>q;
    while(q--){
        ll x;
        cin>>x;
        if(x<=maxi){
            cout<<dp[0][x]<<"\n";
        }
        else{
            ll idx= lower_bound(pref.begin(),pref.end(),x-maxi) - pref.begin();
            if(idx==n){
                cout<<x - pref[n-1]<<"\n";
                continue;
            }
            if((idx+1)==n){
                cout<<x - pref[n-1]<<"\n";
                continue;
            }
            else{
                cout<<dp[idx+1][max(0ll,x - pref[idx])]<<"\n";
            }
            
        }
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    //cin>>t;
    while(t--) solve();
}