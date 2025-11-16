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

void solve(vl &a,str &x){
    ll n = a.size();
    vl where(n + 1,0);
    for(ll i = 0; i < n; i++){
        where[a[i]] = i;
    }
    //dbg(where);
    bool ok = true;
    const ll INF = (ll)1e18;
    
    set<ll> maxi;
    set<ll> pos;



    set<ll> menores;
    set<ll> mayores;
    ll menorDeMenores = INF;
    ll mayorDeMayores = -1;



    for(ll i = 0; i < n; i++){
        mayores.insert(i);
    }
    for(ll i = 0; i < n; i++){
        //dbg(i,i+1, where[i+1]);
        mayores.erase(where[i + 1]);
        //dbg(i,x[i],pos,mayores);
        if(x[where[i+1]] == '1'){
            
            if((ll)pos.size() == 0ll || (ll)mayores.size()==0ll){
                ok = false;
                break;
            }
            else{
                ll ele = *pos.begin();
                if(ele > where[i + 1]){
                    ok = false;
                    break;
                }
                else{
                    if(menores.empty()){
                        menores.insert(ele);
                        menorDeMenores = min(menorDeMenores , a[ele]);
                    }
                    else{
                        if((i + 1) < menorDeMenores){
                            menores.insert(ele);
                            menorDeMenores = min(menorDeMenores , a[ele]);
                        }
                    }
                    ll ele2 = *(prev(mayores.end()));
                    if(ele2 < where[i + 1]){
                        ok = false;
                        break;
                    }
                    else{
                        if(maxi.empty()){
                            maxi.insert(ele2);
                            mayorDeMayores = max(mayorDeMayores , a[ele2]);
                        }
                        else{
                            if((i + 1) > mayorDeMayores){
                                maxi.insert(ele2);
                                mayorDeMayores = max(mayorDeMayores , a[ele2]);
                            }
                        }
                    }
                }
            }    
        }
        
        pos.insert(where[i + 1]);
        
    }
    if(!ok || max((ll)menores.size(),(ll)maxi.size()) > 5ll){
        //dbg(a);
        cout<<"-1\n";
    }
    else{
        str ver(n,'0');
        if(mini.size() > maxi.size()){
            
        }
        for(auto & fin : maxi){
            for(ll i = mini + 1 ; i < fin; i++){
                if(a[i] > a[mini] && a[i] < a[fin]){
                    ver[i]='1';
                }
            }
        }
        
        for(ll i = 0; i < n; i++){
            if(x[i]=='1'){
                if(ver[i]=='0'){
                    dbg("algo esta mal",a,x,mini,maxi);
                    assert(false);
                }
            }
        }
        if(maxi.empty()){
            //dbg("mini es mayor que maxi" , mini, maxi);
            cout<<"0\n";
        }
        else{
            dbg(mini,maxi);
            
            
            cout<<(ll)maxi.size()<<"\n";
            for(auto & e : maxi){
                cout<<mini+1<<" "<<e+1<<"\n";
            }
            
        }
        
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    while(1){
        ll n =rng_ll(1,10);
        vl a(n);
        iota(all(a),1ll);
        shuffle(all(a), rng);
        str x;
        for(ll i = 0; i < n; i++){
            if(rng_ll(0,1) == 1){
                x.push_back('1');
            }
            else x.push_back('0');
        }
        dbg(a,x);
        solve(a,x);
    }
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vl a(n);
        for(auto & e : a)cin>>e;
        str x;
        cin>>x;
        solve(a,x);
    }
}