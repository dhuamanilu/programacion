#include <bits/stdc++.h>
using namespace std;
string to_string (string s){
    return '"' + s + '"';
}
string to_string(const char*s){
    return to_string((string) s);
}
string to_string(char c){
    return string(1,c);
}
string to_string(bool b){
    return b ? "true" : "false";
}
template <typename A>
string to_string(A v);
template <typename A , typename B>
string to_string(pair<A,B> p){
    return "(" + to_string(p.first) + " , " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v){
    bool first=true;
    string res="[";
    for(const auto & x : v){
        if(!first) res +=", ";
        first=false;
        res+=to_string(x);
    }
    res+="]";
    return res;
}
void debug_out(){
    cerr<<endl;
}
template <typename Head,typename...Tail>
void debug_out(Head H,Tail... T){
    cerr<<" "<<to_string(H);
    debug_out(T...);
}
#ifdef LOCAL
#define MACRO(code) do{code}while(false)
#define dbg(x){auto xd = x; cout<<"Line (:"<<__LINE__<<"):"<<"\033[1;34m"<<#x<<"\033[0;32m = \033[35m"<<to_string(xd)<<"\033[0m"<<endl;}
#define dbg(...) MACRO(cout<<"Line(" <<__LINE__<<"): "<<"\033[1;34m" <<"[" <<#__VA_ARGS__<<"]\033[35m:"; debug_out(__VA_ARGS__); cout<<"\033[0m";)

#define GA dbg(0)
#define RAYA cout<<"\033[101m"<<"=============="<<"\033[0m"<<end;
#else
#define dbg(x)
#define dbg(...)
#define GA
#define RAYA
#endif
using ll = long long;
using db = long double;
using str = string;
using pi = pair<int,int>;
using pl = pair<ll,ll>;
#define mp make_pair
#define f first
#define s second

#define tcT template <class T
tcT> using V = vector<T>;
tcT, size_t SZ> using AR = array<T,SZ>;
using vi = V<int>;
using vl = V<ll>;
using vb = V<bool>;
using vpi = V<pi>;

#define sz(x) int((x).size())
#define all(x) begin(x) , end(x)
#define sor(x) sort(all(x))
#define rsz resize
#define pb push_back
#define ft front()
#define bk back()

#define FOR(i,a,b) for(int i = (a) ; i < (b) ; ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for(int i = (b)-1;i>=(a);--i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for(auto & a : x)

// const int MOD = 2e9 + 7;
const int MOD = 998244353 ;
const db PI = acos((db)-1);
//mt19937 rng(0);
mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
tcT> bool ckmin(T&a, const T&b){
    return b < a ? a=b,1:0;
}
tcT> bool ckmax(T&a, const T&b){
    return a < b ? a=b,1:0;
}
void setIn(string s){
    freopen(s.c_str(),"r",stdin);
}
int rng_int(int L,int R){assert(L<=R);
return uniform_int_distribution<int>(L,R)(rng);}
ll rng_ll(ll L,ll R){assert(L<=R);
return uniform_int_distribution<ll>(L,R)(rng);}

ll n, k;
ll b[int(2e5)+5];

ll calc(ll pos) {
    if (pos + k >= n) return 0LL; 

    dbg(pos, (b[pos+1]-b[pos]));
    ll nex = calc(pos+k);
    ll res = max(0LL, nex - (b[pos+1]-b[pos]));

    return res;
}

ll modinv(ll x, ll p) {
    ll res = 1;

    while (p > 0) {
        if (p & 1) {
            res *= x;
            res %= MOD;
        }
        p/=2;
        x *= x;
        x %= MOD;
    }

    return res;
}

void solve(){
    cin >> n >> k;
    for (ll i = 0; i < n-k+1; ++i) cin >> b[i];

    vl c(k);
    for (ll i = 0; i < k; ++i) c[i] = calc(i);
    dbg(c);

    ll total = b[0];
    dbg(total);
    for (ll i = 0; i < k; ++i) total -= c[i];
    dbg(total);

    if (total < 0) {
        cout << 0 << "\n";
    } else {
        ll up = 1;
        ll down = 1;

        for (ll i = 1; i <= k-1; ++i) {
            down *= i;
            down %= MOD;
        }
        for (ll i = 0; i < k-1; ++i) {
            up *= total+k-1 - i;
            up %= MOD;
        }

        ll res = up * modinv(down, MOD-2);
        res %= MOD;

        cout << res << "\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}