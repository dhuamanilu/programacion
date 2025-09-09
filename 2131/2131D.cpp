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
    vector<vl> a(n);
    for(int i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        u--;
        v--;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    if(n==2){
        cout<<"0\n";
        return;
    }
    ll mini=(ll)1e18,xd=0;
    for(ll i=0;i<n;i++){
        xd+=a[i].size()==1;
    }
    for(ll i=0;i<n;i++){
        ll vec=0;
        for(auto & e : a[i]){
            vec+=a[e].size()==1;
        }
        mini=min(mini,xd-vec);
    }
    cout<<mini<<"\n";

}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    cin>>t;
    while(t--) solve();
}