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
    ll n,m,k;
    cin>>n>>m>>k;
    vector<vl> a(n,vl(m));
    /* 
    0 '.', 1 '#', or 2 'g', where '.' — is an empty cell, '#' — is stone, 
    'g' — is gold. It is guaranteed that at least one of the cells is empty.
    */
   ll tot=0;
    for(auto & e : a){
        for(auto &e2 : e){
            char xd;
            cin>>xd;
            if(xd=='.') e2=0;
            else if(xd=='#') e2=1;
            else{
                e2=2;
                tot++;
            } 
        }
    }
    vector<vl> pref(n,vl(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ll val1=i>=1 ? pref[i-1][j] : 0ll;
            ll val2=j>=1 ? pref[i][j-1] : 0ll;
            ll val3=(i>=1 && j>=1) ? pref[i-1][j-1] : 0ll;
            pref[i][j]=(a[i][j]==2)+val1+val2-val3;
        }
    }
    auto query=[&](ll x1,ll y1,ll x2,ll y2){
        ll val1=y1>=1 ? pref[x2][y1-1] : 0ll;
        ll val2=x1>=1 ? pref[x1-1][y2] : 0ll;
        ll val3=(x1>=1 && y1>=1) ? pref[x1-1][y1-1] : 0ll;
        return pref[x2][y2]-val1-val2+ val3;
    };
    ll ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==0){
                ll x1=max(0ll,i-(k-1));
                ll y1=max(0ll,j-(k-1));
                ll x2=min(n-1,i+(k-1));
                ll y2=min(m-1,j+(k-1));
                ll calc=query(x1,y1,x2,y2);
                ans=max(ans,tot-calc);
            }
        }
    }
    cout<<ans<<"\n";


}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    cin>>t;
    while(t--) solve();
}