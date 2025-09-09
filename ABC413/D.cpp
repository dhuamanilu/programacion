#pragma GCC optimize ("Ofast")
//? #pragma GCC target ("avx,avx2")
#pragma GCC optimize ("trapv")
#undef _GLIBCXX_DEBUG //? for Stress Testing

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

tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; } // set a = max(a,b)

void setIn(string s) { freopen(s.c_str(), "r", stdin); }
//? /Custom Helpers
//? Generator
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
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
int rng_int(int L, int R) { assert(L <= R);
	return uniform_int_distribution<int>(L,R)(rng);  }
ll rng_ll(ll L, ll R) { assert(L <= R);
	return uniform_int_distribution<ll>(L,R)(rng);  }

string brute(vl a){
    sor(a);
    auto check=[](vl &arr){
        frac r(arr[1],arr[0]);
        bool ok=true;
        for(ll i=1;i<arr.size();i++){
            if(((frac(arr[i-1])*r) != frac(arr[i]))){
                ok=false;
                break;
            }
        }
        return ok;
    };
    do{
        if(check(a)) return "Yes";
    }while(next_permutation(all(a)));
    return "No";
}

string solve(vl a){
    sort(a.begin(),a.end());
    //dbg(a);
    auto check=[](vl &arr){
        frac r(arr[1],arr[0]);
        bool ok=true;
        for(ll i=1;i<arr.size();i++){
            
            if(abs(arr[i-1]) > (LLONG_MAX / abs(r.n))){
                dbg(arr[i-1],LLONG_MAX , r.n,r.d);
                ok=false;
                break;
            }
            if(((frac(arr[i-1])*r) != frac(arr[i]))){
                ok=false;
                break;
            }
        }
        return ok;
    };
    if(check(a)){
        return "Yes";
    }
    else{
        //for(auto & e : a)e=abs(e);
        sort(a.begin(),a.end(),[](auto c,auto d){
            return abs(c) < abs(d);
        });
        //dbg("alternado",a);
        if(check(a)){
            return "Yes";
        }
        else{
            ll cont=0;
            map<ll,ll> m;
            for(auto & e : a) m[abs(e)]++;
            if(m.size()==1){
                ll pos=0,neg=0;
                for(auto & e: a){
                    if(e>0) pos++;
                    else neg++;
                }
                if(abs(pos-neg)<=1){
                    return "Yes";
                }
                else return "No";
            }
            else return "No";
        }
    }      
}
int main() {
    while(0){  
        ll num,deno;
        const ll MAX=1000;
        
        ll mask=rng_ll((1ll<<13),((1ll<<14)-1)),pri=1;
        for(ll j=0;j<14;j++){
            if((1ll<<j)&mask){
                pri*=(j+1);
            }
        }
        while(true){    
            deno=rng_ll(2,MAX);
            num=rng_ll(1,deno-1);
            ll signo=rng_ll(0,1);
            if(signo)num*=-1;
            
            
            frac result(pri*num,deno);
            if(result.n%result.d==0){
                break;
            }
        }
        
        vl a={pri};
        frac r(num,deno);
        while(a.size() < 10000){
            frac act(a.back());
            frac sgte=act * r;
            if((sgte.n%sgte.d)!=0){
                break;
            }
            else{
                a.push_back(sgte.n/sgte.d);
            }
        }
        dbg(a);
        auto ans2=solve(a);
        if(ans2!="Yes"){
            dbg(a,ans2);
            assert(false);
        }
        else dbg("ok");
        /*auto ans1=brute(a);
        auto ans2=solve(a);
        if(ans1!=ans2){
            dbg(a,ans1,ans2);
            assert(false);
        }
        else dbg("ok");*/
    }
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        vl a(n);
        for(auto & e : a)cin>>e;
        cout<<solve(a)<<"\n";
    }
}