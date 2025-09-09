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
    vector<pl> a(n);
    for(auto & e : a){
        cin>>e.first>>e.second;
        ll u=min(e.first,e.second);
        ll v=max(e.first,e.second);
        e.first=u;
        e.second=v;
    }
    sort(a.begin(),a.end(),[](pl &c,pl &d){
        if(c.second!=d.second){
            return c.second < d.second;
        }
        else{
            return c.first < d.first;
        }
    });
    //sort(a.begin(),a.end());
    //dbg(a);
    const ll BIG=(ll)1e12;
    vl dp(n,BIG);
    auto get=[&](ll idx,ll l){
        ll s=0,e=idx,m=s+(e-s)/2,guarda=-1;
        while(s<=e){
            m=s+(e-s)/2;
            if(a[m].second < l){
                guarda=m;
                s=m+1;
            }
            else{
                e=m-1;
            }
        }
        return guarda;
    };
    ll lim=a[0].first;
    for(ll i=0;i<n;i++){
        lim=max(lim,a[i].first);
        for(ll j=lim;j<=a[i].second;j++){
            ll idx=get(i,j);
            ll xd=(idx==-1) ? 0 : dp[idx];
            dp[i]=min(dp[i],1+xd);
        }
        
    }
    //dbg(dp);
    cout<<dp[n-1]<<"\n";
    vl points;
    for(ll i=0;i<n;i++){
        ll j=i,izq=a[i].first,der=a[i].second;
        while(j<n && dp[i]==dp[j]){
            izq=max(izq,a[j].first);
            der=min(der,a[j].second);
            j++;
        }
        /*dbg(izq);
        dbg(der);*/
        assert(izq<=der);
        points.emplace_back(izq);
        i=j-1;
    }
    for(auto & e : points){
        cout<<e<<" ";
    }
    cout<<"\n";
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    //cin>>t;
    while(t--) solve();
}