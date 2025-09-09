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
#define all(x) begin(x), end(x)

#define dbg(x) cout << "Line(" << __LINE__ << "): " << "\033[1;34m" << #x << "\033[0;32m = \033[35m" << to_string(x) << "\033[0m" << endl;
#define GA dbg(0)
#define RAYA   dbg("================================");

void setIn(string s) { freopen(s.c_str(), "r", stdin); }
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

ll rng_ll(ll L, ll R) { assert(L <= R);
	return uniform_int_distribution<ll>(L,R)(rng);  }
string brute(vl a,vl b){
    ll n=a.size();
    for(ll i=0;i<(1ll<<(n-1));i++){
        vl ops;
        for(ll j=0;j<(n-1);j++){
            if((1ll<<j)&i){
                ops.push_back(j);
            }
        }
        do{
            vl nuevo=a;
            for(auto & e  : ops){
                nuevo[e]^=nuevo[e+1];
            }
            bool ok=true;
            for(ll j=0;j<n;j++){
                if(nuevo[j]!=b[j]){
                    ok=false;
                    break;
                }
            }
            if(ok){
                dbg(a);
                dbg(b);
                dbg(ops);
                return "YES";
            }
        }while(next_permutation(all(ops)));
    }
    return "NO";
}
string solve(vl a,vl b){
    ll n=a.size();
    
    vl vis(n,0);
    for(int i=0;i<n;i++){
        if(vis[i]){
            if(a[i]!=b[i]){
                return "NO";
            }
        }
        else{
            if(a[i]!=b[i]){
                if(i==(n-1)){
                    return "NO";
                }
                else{
                    if(a[i+1]==(a[i]^b[i])){
                        vis[i]=1;
                        a[i]^=a[i+1];
                        continue;
                    }
                    ll need=a[i]^b[i],j=i+1,xo=a[j];
                    while((j+1)<n && xo!=need){
                        vis[j]=1;                        
                        xo^=a[++j];
                    }
                    if(xo!=need){
                        return "NO";
                    }
                    else{
                        ll k=i;
                        while(k<j){
                            ll val=a[k];
                            a[++k]=xo;
                            xo^=val;
                        }
                        a[i]=b[i];
                    }
                }
                
            }
        }
    }
    return "YES";
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    cin>>t;
    while(0){
        ll n=rng_ll(1,11);
        vl a(n),b(n);
        for(auto & e : a) e=rng_ll(0,1024);
        for(ll i=0;i<n;i++) b[i]=a[i];
        ll tam=rng_ll(1,2);
        for(ll i=0;i<tam;i++){
            ll idx=rng_ll(0,n-1);
            b[idx]=rng_ll(0,1024);
        }
        
        auto ans1=brute(a,b);
        auto ans2=solve(a,b);
        if(ans1!=ans2){
            dbg(ans1);
            dbg(ans2);
            dbg(a);
            dbg(b);
            assert(false);
        }
        else dbg("ok");
    }
    //dbg(brute({1,2,3},{1,2,3}));
    while(t--) {
        ll n;
        cin>>n;
        vl a(n),b(n);
        for(auto & e : a)cin>>e;
        for(auto & e : b)cin>>e;
        cout<<solve(a,b)<<"\n";
    }
}