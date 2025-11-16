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
ll brute(vl a,ll d){
    ll n = a.size(),ans=ll(1e15);
    for(ll i=0;i <(1ll<<n);i++){
        map<ll,ll> appear;
        ll cont = 0;
        for(ll j=0;j < n;j++){
            if((1ll<<j)&i){
                appear[a[j]]++;
            }
            else{
                cont++;
            }
        }
        bool ok=true;
        for(auto & [ele,frec] : appear){
            if(appear.count(ele + d) || appear.count(ele - d)){
                ok=false;
                break;
            }
        }
        if(ok){
            ans = min(ans,cont);
        }
    }
    return ans;
}
ll solve(vl &a,ll d){
    if(d==0){
        set<ll> xd;
        for(auto & e : a)xd.insert(e);
        return (ll)a.size() - (ll)xd.size();
    }
    ll maxi = *(max_element(all(a)));
    vl weights(maxi+1,0);
    for(auto & e : a){
        weights[e]++;
    }
    
    vl vis(maxi + 1 ,0);
    V<vl> paths;

    for(ll i=0;i<=maxi;i++){
        if(vis[i] || weights[i]==0) continue;
        ll j = i;
        vl path= {j};
        vis[j]=true;
        while( (j + d) <= maxi && weights[j + d] > 0 && !vis[j+d]){
            j+=d;
            vis[j]=true;
            path.push_back(j);
        }
        if(path.size() > 1){
            paths.push_back(path);
        }
    }
    //dbg(paths);
    ll ans=0;
    for(auto & path : paths){
        ll tam = path.size();
        V<vl> dp(tam,vl(2,0));
        dp[0][1] = weights[path[0]]; 
        for(ll i=1;i < tam;i++){
            dp[i][0] = dp[i-1][1];
            dp[i][1] = min(dp[i-1][0] , dp[i-1][1]) + weights[path[i]];
        }
        ll contr = min(dp[tam-1][0] , dp[tam-1][1]);
        ans+=contr;
    }
    return ans;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    //cin>>t;
    while(false){
        ll n= rng_ll(1,17) , d=rng_ll(1,20);
        vl a(n);
        for(auto & e :a){
            e = rng_ll(1,51);
        }
        ll ans1 = brute(a,d),ans2=solve(a,d);
        if(ans1!=ans2){
            dbg("xd : ",a,d,ans1,ans2);
            assert(false);
        }   
        else{
            dbg("ok");
        }
    }
    while(t--){
        ll n,d;
        cin>>n>>d;
        vl a(n);
        for(auto & e : a)cin>>e;
        sor(a);
        cout<<solve(a,d)<<"\n";
    }
}