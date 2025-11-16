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

/*#ifdef LOCAL
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
#endif*/
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

str solve(str hour,ll x,ll y){
    //dbg("solving for",hour,x,y);
    char h1=hour[0],h2=hour[1],dospuntos = hour[2],m1 = hour[3],m2 = hour[4];
    auto ban=[&](char a){
        if(a=='2' || a=='4'){
            return true;
        }
        else return false;
    };
    if((ban(h2)  ||  h2=='0' || (h1=='1' && h2=='1')) && ban(m2)){
        return "No closest valid time possible";
    }
    map<ll,ll> xd;
    vl especiales={5,6,8,9};
    for(auto & e : especiales){
        xd[e]++;
    }
    auto can=[&](char a){
        ll num = a-'0';
        return xd.count(num);
    };
    ll minH,minM;
    const ll INF = 1e9;
    if(ban(h2) || h2=='0' || (h1=='1' && h2=='1')){
        minH=INF;
    }
    else if(can(h2)){
        minH=60;
    }
    else{
        minH=360;
    }

    if(ban(m2)){
        minM = INF;
    }
    else if(can(m2)){
        minM=1;
    }
    else if(m2=='1' || m2=='3' || m2=='7'){
        minM=6;
    }
    else{
        assert(m2=='0');
        minM=8;
    }
    auto cambiar=[](char b){
        if(b=='5') return '6';
        else if(b=='6') return '5';
        else if(b=='8') return '9';
        else{
            assert(b=='9');
            return '8';
        }
    };
    auto cambiar2=[](char b){
        if(b=='1') return '7';
        else if(b=='3') return '9';
        else{
            assert(b=='7');
            return '1';
        }
    };
    
    const long long INFLL = (long long)4e18;
    char orig_h2 = h2;
    char orig_m2 = m2;

    
    bool hasHour = true;
    bool hasMin  = true;
    char hour_candidate = orig_h2;
    char min_candidate  = orig_m2;

    
    auto in = [&](char c, const char* s)->bool {
        for(const char* p = s; *p; ++p) if(*p == c) return true;
        return false;
    };
    const char* set_especiales = "5689"; 
    const char* set_cambiar2 = "137";    
    const char* set_min_136 = "137";

    if(minH == INF) {
        hasHour = false;
    } else {
        if(minH == 60) {
            if(in(orig_h2, set_especiales)) hour_candidate = cambiar(orig_h2);
            else hasHour = false;
        } else {
            if(in(orig_h2, set_cambiar2)) hour_candidate = cambiar2(orig_h2);
            else hasHour = false;
        }
    }

    if(minM == INF) {
        hasMin = false;
    } else {
        if(minM == 1) {
            if(in(orig_m2, set_especiales)) min_candidate = cambiar(orig_m2);
            else hasMin = false;
        } else if(minM == 6) {
            if(in(orig_m2, set_cambiar2)) min_candidate = cambiar2(orig_m2);
            else hasMin = false;
        } else {
            if(orig_m2 == '0') min_candidate = '8';
            else hasMin = false;
        }
    }

    if(!hasHour && !hasMin) {
        return "No closest valid time possible";
    }
    long long costHour = hasHour ? (minH * x) : INFLL;
    long long costMin  = hasMin  ? (minM * y) : INFLL;
    if(!hasMin && hasHour) {
        h2 = hour_candidate;
    } else if(!hasHour && hasMin) {
        m2 = min_candidate;
    } else {
        if(costHour < costMin) {
            h2 = hour_candidate;
        } else if(costHour > costMin) {
            m2 = min_candidate;
        } else {
            auto toHH = [&](char a, char b)->int { return (a - '0')*10 + (b - '0'); };
            auto toMM = [&](char a, char b)->int { return (a - '0')*10 + (b - '0'); };

            int oldHH = toHH(h1, orig_h2);
            int oldMM = toMM(m1, orig_m2);

            int hh_hour = toHH(h1, hour_candidate);
            int mm_hour = oldMM;

            int hh_min  = oldHH;
            int mm_min  = toMM(m1, min_candidate);

            auto cycDiff = [&](int a, int b, int mod)->int {
                int d = abs(a - b);
                return min(d, mod - d);
            };

            int dh_hour = cycDiff(oldHH, hh_hour, 12);
            int dm_hour = cycDiff(oldMM, mm_hour, 60);
            int move_hour = dh_hour * 60 + dm_hour;

            int dh_min = cycDiff(oldHH, hh_min, 12);
            int dm_min = cycDiff(oldMM, mm_min, 60);
            int move_min = dh_min * 60 + dm_min;

            if(move_hour < move_min) {
                h2 = hour_candidate;
            } else if(move_hour > move_min) {
                m2 = min_candidate;
            } else {
                int val_hour = hh_hour * 60 + mm_hour;
                int val_min  = hh_min  * 60 + mm_min;
                if(val_hour <= val_min) h2 = hour_candidate;
                else m2 = min_candidate;
            }
        }
    }
    string res;
    res.push_back(h1);
    res.push_back(h2);
    res.push_back(dospuntos);
    res.push_back(m1);
    res.push_back(m2);
    return res;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    //cin>>t;
    while(0){
        ll h1 = rng_ll(0,1) , h2 , m1,m2;
        if(h1==0){
            h2=rng_ll(1,9);
        }
        else{
            h2=rng_ll(0,2);
        }
        m1 = rng_ll(0,5);
        m2 = rng_ll(0,9);
        string hour;
        hour.push_back('0' + h1);
        hour.push_back('0' + h2);
        hour.push_back(':');
        hour.push_back('0' + m1);
        hour.push_back('0' + m2);
        ll x = rng_ll(1,100),y=rng_ll(1,100);
        auto ans = solve(hour,x,y);
        //dbg(hour,x,y,ans);
    }
    while(t--){
        string hour;
        cin>>hour;
        ll x,y;
        cin>>x>>y;
        auto ans = solve(hour,x,y);
        cout<<ans<<"\n";
    }
}