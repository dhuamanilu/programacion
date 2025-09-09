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
struct frac {
	ll n,d;
	frac(ll _n, ll _d) {
		n = _n, d = _d;
		ll g = __gcd(n,d); n /= g, d /= g;
		if (d < 0) n *= -1, d *= -1;
	}
	frac(ll _n) : frac(_n,1) {}
	frac() : frac(0) {}
	friend frac abs(frac F) { return frac(abs(F.n),F.d); }
	friend string ts(const frac& a) { return to_string(a.n)+"/"+to_string(a.d); }
 
	friend bool operator<(const frac& l, const frac& r) { return l.n*r.d < r.n*l.d; }
	friend bool operator==(const frac& l, const frac& r) { return l.n == r.n && l.d == r.d; }
	friend bool operator!=(const frac& l, const frac& r) { return !(l == r); }
 
	frac operator-() const { return frac(-n,d); }
	friend frac operator+(const frac& l, const frac& r) { return frac(l.n*r.d+r.n*l.d,l.d*r.d); }
	friend frac operator-(const frac& l, const frac& r) { return frac(l.n*r.d-r.n*l.d,l.d*r.d); }
	friend frac operator*(const frac& l, const frac& r) { return frac(l.n*r.n,l.d*r.d); }
	friend frac operator*(const frac& l, int r) { return l*frac(r,1); }
	friend frac operator*(int r, const frac& l) { return l*r; }
	friend frac operator/(const frac& l, const frac& r) { return l*frac(r.d,r.n); }
	friend frac operator/(const frac& l, const int& r) { return l/frac(r,1); }
	friend frac operator/(const int& l, const frac& r) { return frac(l,1)/r; }
 
	friend frac& operator+=(frac& l, const frac& r) { return l = l+r; }
	friend frac& operator-=(frac& l, const frac& r) { return l = l-r; }
	template<class T> friend frac& operator*=(frac& l, const T& r) { return l = l*r; }
	template<class T> friend frac& operator/=(frac& l, const T& r) { return l = l/r; }
};
void solve(){
    ll n;
    cin>>n;
    vector<pl> a(n);
    for(auto & e : a)cin>>e.first>>e.second;
    map<pl,ll> pends;
    map<ll,ll> dex;
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            auto [x1,y1]=a[i];
            auto [x2,y2]=a[j];
            if(x1==x2){
                dex[x1]++;
            }
            else{
                frac pend((y1-y2),(x1-x2));
                dbg(i+1,j+1,a[i],a[j],pend.n,pend.d);
                pends[{pend.n,pend.d}]++;
            }
        }
    }
    //dbg(pends);
    //dbg(dex);
    ll ans=0,tam=dex.size();
    ans+=((tam*(tam-1))/2);
    for(auto & [xd,cant] : pends){
        ans+=(cant*(cant-1))/2;
    }
    //dbg(ans);
    map<ll,vector<pl>> xP,yP;
    for(ll i=0;i<n;i++){
        auto [x1,y1]=a[i];
        xP[x1].push_back(a[i]);
        yP[y1].push_back(a[i]);
    }
    auto get_pend=[&](pl &par1,pl &par2){
        return frac((par1.second - par2.second),(par1.first - par2.first));
    };
    ll cant=0;
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            auto p1=a[i];
            auto p2=a[j];
            if(xP[p1.first].size() > 1 &&xP[p2.first].size() > 1){
                pl p3,p4;
                for(auto & e : xP[p1.first]){
                    if(e!=a[i]){
                        p3=e;
                        break;
                    }
                }
                for(auto & e : xP[p2.first]){
                    if(e!=a[j]){
                        p4=e;
                        break;
                    }
                }
                {
                    frac pend1=get_pend(p1,p2);
                    frac pend2=get_pend(p3,p4);
                    frac pend3=get_pend(p1,p3);
                    frac pend4=get_pend(p2,p4);
                    if(pend1==pend2 && pend3==pend4){
                        //dbg("se repite 1era vez",i+1,j+1,p1,p2,p3,p4);
                        cant++;
                    }
                }
                {
                    frac pend1=get_pend(p1,p4);
                    frac pend2=get_pend(p2,p3);
                    frac pend3=get_pend(p1,p3);
                    frac pend4=get_pend(p2,p4);
                    if(pend1==pend2 && pend3==pend4){
                        //dbg("se repite 2da vez",i+1,j+1,p1,p2,p3,p4);
                        cant++;
                    }
                }
                
            }
            if(yP[p1.second].size() > 1 &&yP[p2.second].size() > 1){
                pl p3,p4;
                for(auto & e : yP[p1.second]){
                    if(e!=a[i]){
                        p3=e;
                        break;
                    }
                }
                for(auto & e : yP[p2.second]){
                    if(e!=a[j]){
                        p4=e;
                        break;
                    }
                }
                {
                    frac pend1=get_pend(p1,p2);
                    frac pend2=get_pend(p3,p4);
                    frac pend3=get_pend(p1,p3);
                    frac pend4=get_pend(p2,p4);
                    if(pend1==pend2 && pend3==pend4){
                        //dbg("se repite 3ra vez",i+1,j+1,p1,p2,p3,p4);
                        cant++;
                    }
                }
            }
        }
        RAYA;
    }
    assert((cant%2)==0);
    cout<<ans - (cant/2)<<"\n";
    
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    //cin>>t;
    while(t--) solve();
}