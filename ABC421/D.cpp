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
    ll rt,ct,ra,ca;
    cin>>rt>>ct>>ra>>ca;
    ll n,m,l;
    cin>>n>>m>>l;
    V<pair<char,ll>> a(m),b(l);
    for(auto & e : a){
        cin>>e.first>>e.second;
    }
    for(auto & e : b){
        cin>>e.first>>e.second;
    }
    ll i=0,j=0,ans=0;
    auto mover=[](ll x,ll y,ll cuanto ,char d){
        if(d=='U'){
            x-=cuanto;
        }
        else if(d=='R'){
            y+=cuanto;
        }
        else if(d=='D'){
            x+=cuanto;
        }
        else{
            y-=cuanto;
        }
        return make_pair(x,y);
    };
    while(i< m && j < l){
        //dbg("mira",i,j,m,l);
        ll cant = min(a[i].s,b[j].s);
        if(a[i].f == b[j].f){
            if(make_pair(rt,ct)==make_pair(ra,ca)){
                ans+=cant;
            }
        }
        else{
            if(a[i].f =='L' && b[j].f=='U'){
                //ra >= rt BIEN DOBLE CHECK
                if((ra - rt) == (ct-ca) && (ct-ca)>0 && (ct-ca)<=cant){
                    ans++;
                }
            }
            else if(a[i].f =='L' && b[j].f=='D'){
                // rt >= ra BIEN DOBLE CHECK
                if((rt - ra) == (ct-ca) && (ct-ca)>0 && (ct-ca)<=cant){
                    ans++;
                }
            }
            else if(a[i].f =='U' && b[j].f=='R'){
                // rt >= ra BIEN DOBLE CHECK
                if((rt - ra) == (ct-ca) && (ct-ca)>0 && (ct-ca)<=cant){
                    ans++;
                }
            }
            else if(a[i].f =='U' && b[j].f=='L'){
                // rt >= ra bien doble check
                if((rt- ra) == (ca-ct) && (ca-ct)>0 && (ca-ct)<=cant){
                    ans++;
                }
            }
            else if(a[i].f =='R' && b[j].f=='D'){
                // rt >= ra bien doble check
                if((rt - ra) == (ca-ct) && (ca-ct)>0 && (ca-ct)<=cant){
                    ans++;
                }
            }
            else if(a[i].f =='R' && b[j].f=='U'){
                // ra>= rt BIEN DOBLE CHECK
                if((ra - rt) == (ca-ct) && (ca-ct)>0 && (ca-ct)<=cant){
                    ans++;
                }
            }
            else if(a[i].f =='D' && b[j].f=='L'){
                // ra>= rt  BIEN DOBLE CHECK
                if((ra - rt) == (ca-ct) && (ca-ct)>0 && (ca-ct)<=cant){
                    ans++;
                }
            }
            else if(a[i].f =='D' && b[j].f=='R'){
                // ra>= rt  BIEN DOBLE CHECK
                if((ra - rt) == (ct-ca) && (ct-ca)>0 && (ct-ca)<=cant){
                    ans++;
                }
            }
            else if(a[i].f =='L' && b[j].f=='R'){
                if(rt==ra && (ct-ca)<=2*cant && (ct-ca)>0 && (ct-ca)%2==0){
                    ans++;
                }
            }
            else if(a[i].f=='R' && b[j].f=='L'){
                if(rt==ra && (ca-ct)<=2*cant && (ca-ct)>0 && (ca-ct)%2==0){
                    ans++;
                }
            }
            else if(a[i].f=='U' && b[j].f=='D'){
                if(ct==ca && (rt-ra)<=2*cant && (rt-ra)>0 && (rt-ra)%2==0){
                    ans++;
                }
            }
            else if(a[i].f=='D' && b[j].f=='U'){
                if(ct==ca && (ra-rt)<=2*cant && (ra-rt)>0 && (ra-rt)%2==0){
                    ans++;
                }
            }
            
        }
        a[i].s-=cant;
        b[j].s-=cant;
        
        auto mov = mover(rt,ct,cant,a[i].f);
        rt = mov.f;
        ct = mov.s;
        auto mov2 = mover(ra,ca,cant,b[j].f);
        ra = mov2.f;
        ca = mov2.s;
        if(a[i].s==0) i++;
        if(b[j].s==0) j++;
    }
    while(i<m){
        ll cant =a[i].s;
        
        if(a[i].f =='L'){
            if(rt==ra && (ct-ca)<=cant && (ct-ca)>0){
                ans++;
            }
        }
        else if(a[i].f=='R'){
            if(rt==ra && (ca-ct)<=cant && (ca-ct)>0){
                ans++;
            }
        }
        else if(a[i].f=='U'){
            if(ct==ca && (rt-ra)<=cant && (rt-ra)>0){
                ans++;
            }
        }
        else if(a[i].f=='D'){
            if(ct==ca && (ra-rt)<=cant && (ra-rt)>0){
                ans++;
            }
        }  
        a[i].s-=cant;
        auto mov = mover(rt,ct,cant,a[i].f);
        rt = mov.f;
        ct = mov.s;
        if(a[i].s==0) i++;
    }
    while(j<l){
        ll cant =b[j].s;
        if(b[j].f=='R'){
            if(rt==ra && (ct-ca)<=cant && (ct-ca)>0){
                ans++;
            }
        }
        else if(b[j].f=='L'){
            if(rt==ra && (ca-ct)<=cant && (ca-ct)>0){
                ans++;
            }
        }
        else if(b[j].f=='D'){
            if(ct==ca && (rt-ra)<=cant && (rt-ra)>0){
                ans++;
            }
        }
        else if(b[j].f=='U'){
            if(ct==ca && (ra-rt)<=cant && (ra-rt)>0 ){
                ans++;
            }
        }   
        b[j].s-=cant;
        auto mov2 = mover(ra,ca,cant,b[j].f);
        ra = mov2.f;
        ca = mov2.s;
        if(b[j].s==0) j++;
    }
    dbg(ans,i,j,m,l);
    assert(i==m && j==l);
    cout<<ans<<"\n";
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    //cin>>t;
    while(t--) solve();
}