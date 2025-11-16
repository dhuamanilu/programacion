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
set<ll> primes;
const int N = 100000 + 5;
void init(){
    vl isPrime(N , 1);
    for(ll i = 2; i < N; i++){
        if(isPrime[i]){
            for(ll j = 2 * i ; j < N ;j += i){
                isPrime[j] = 0;
            }
        }
    }
    for(ll i = 2; i < N; i++){
        if(isPrime[i]) primes.insert(i);
    }
}
void solve(){
    ll n;
    cin>>n;
    ll primero = *primes.lower_bound(n/2);
    cout<<primero<<" ";
    set<ll> vis;
    vis.insert(primero);
    for(ll i = 1; i <= (n/2); i++){
        if(primero - i >= 1){
            cout<<primero - i <<" ";
            vis.insert(primero - i);
        }
        if((primero + i) <=n){
            cout<<primero + i<<" ";
            vis.insert(primero + i);
        }
    }
    for(ll i = 1;i <= n; i++){
        if(vis.count(i)) continue;
        cout<<i<<" ";
    }
    cout<<"\n";
    
    
    
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    init();
    ll t=1;
    cin>>t;
    while(t--) solve();
}