//#pragma GCC optimize ("Ofast")
//? #pragma GCC target ("avx,avx2")
//#pragma GCC optimize ("trapv")
//#undef _GLIBCXX_DEBUG //? for Stress Testing
#include <bits/stdc++.h>
using namespace std;

//* Debugger
string to_string(string s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(char c) {
    return string(1, c);
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

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define MACRO(code) do {code} while (false)
#define dbg(x)      {auto xd = x; cout << "Line(" << __LINE__ << "): " << "\033[1;34m" << #x << "\033[0;32m = \033[35m" << to_string(xd) << "\033[0m" << endl;}
#define dbg(...)    MACRO(cout << "Line(" << __LINE__ << "): " << "\033[1;34m" << "[" << #__VA_ARGS__ << "]\033[35m:"; debug_out(__VA_ARGS__); cout << "\033[0m";)

#define GA          dbg(0)
#define RAYA        cout << "\033[101m" << "================================" << "\033[0m" << endl;
#else
#define dbg(x)
#define dbg(...)
#define GA
#define RAYA
#endif
//* /Debugger

using ll = long long;
using db = long double; // or double if tight TL
using str = string;

using pi = pair<int,int>;
using pl = pair<ll, ll>;
#define mp make_pair
#define f first
#define s second

#define tcT template<class T
tcT> using V = vector<T>;
tcT, size_t SZ> using AR = array<T,SZ>;
using vi = V<int>;
using vl = V<ll>;
using vb = V<bool>;
using vpi = V<pi>;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsz resize
#define pb push_back
#define ft front()
#define bk back()

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

const int MOD = 1e9+7;
const db PI = acos((db)-1);
mt19937 rng(0); // or mt19937_64
//* mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; } // set a = max(a,b)

void setIn(string s) { freopen(s.c_str(), "r", stdin); }
//? /Custom Helpers
//? Generator
int rng_int(int L, int R) { assert(L <= R);
	return uniform_int_distribution<int>(L,R)(rng);  }
ll rng_ll(ll L, ll R) { assert(L <= R);
	return uniform_int_distribution<ll>(L,R)(rng);  }

void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    V<vl> pref(n,vl(2,0));
    pref[0][s[0]-'0']++;
    for(ll i=1;i<n;i++){
        pref[i] = pref[i-1];
        pref[i][s[i] - '0']++;
    }
    auto query=[&](ll which, ll l,ll r){
        ll val = l>=1 ? pref[l-1][which] : 0ll;
        return pref[r][which] - val;

    };
    V<set<ll>> pos(2);
    for(ll i=0;i<n;i++){
        pos[s[i]-'0'].insert(i);
    }
    auto get_next=[&](ll which, ll position){
        auto xd = pos[which].upper_bound(position);
        if(xd == pos[which].end()){
            return n;
        }
        else return *xd;
    };
    const ll INF = ll(1e15);
    auto calc=[&](ll ele){
        ll ans=INF;
        
        for(ll i=0;i<n;i++){
            ll othersLeft = query(ele ^ 1 , 0 , i);
            ll mineLeft = query(ele,0,i);
            ll contrLeft = 0;
            if(mineLeft!=0){
                contrLeft = mineLeft + (2*othersLeft);
            }
           
            //GA;
            ll posNext = get_next(ele , i);
            ll othersRight = 0;
            ll mineRight = 0;
            //GA;
            if(posNext == n){
                othersRight = query(ele^1, i , n-1);
                // mine right remains 0
            }
            else{
                //assert(posNext < n);
                //dbg(i,ele,posNext);
                othersRight = query(ele^1, posNext , n-1);
                mineRight = query(ele,posNext,n-1);
            }
            //GA;
            ll contrRight = 0;
            if(mineRight!=0){
                contrRight = mineRight + 2*(othersRight);
            }
            ll contr = contrLeft + contrRight;
            ans = min (ans,contr);
        }
        return ans;
    };
    ll ans = min(calc(0),calc(1));
    cout<<ans<<"\n";
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    cin>>t;
    while(t--) solve();
}