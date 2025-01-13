//#pragma GCC optimize ("Ofast")
//? #pragma GCC target ("avx,avx2")
#pragma GCC optimize ("trapv")
#undef _GLIBCXX_DEBUG //? for Stress Testing
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "../debugICPC.h"
#define chk(...) if (!(__VA_ARGS__)) cerr << "\033[41m" << "Line(" << __LINE__ << ") -> function(" \
	 << __FUNCTION__  << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")" << "\033[0m" << "\n", exit(0);

#define MACRO(code) do {code} while (false)
#define RAYA MACRO(cerr << "\033[101m" << "================================" << "\033[0m" << endl;)
#else
#define dbg(...)

#define chk(...)
#define RAYA
#endif

const auto beg_time = std::chrono::high_resolution_clock::now();
// https://stackoverflow.com/questions/47980498/accurate-c-c-clock-on-a-multi-core-processor-with-auto-overclock?noredirect=1&lq=1
double time_elapsed() {
	return chrono::duration<double>(std::chrono::high_resolution_clock::now() -
	                                beg_time)
	    .count();
}

// building blocks
using ll  = long long;
using db  = long double; // or double, if TL is tight
using str = string;      // yay python!
//? priority_queue for minimum
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
using ull  = unsigned long long;
//? using i64  = long long;
//? using u64  = uint64_t;
//? using i128 = __int128;
//? using u128 = __uint128_t;
//? using f128 = __float128;
// pairs
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
#define mp make_pair
#define f first
#define s second

#define tcT template <class T
#define tcTU tcT, class U
//! ^ lol this makes everything look weird but I'll try it
tcT > using V = vector<T>;
tcT, size_t SZ > using AR = array<T, SZ>;
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;

// vectors
// oops size(x), rbegin(x), rend(x) need C++17
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()
#define ts to_string



// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)



const int MOD = 1e9+7;
const ll BIG = 1e18;  //? not too close to LLONG_MAX
const db PI = acos((db)-1);
mt19937 rng(0); // or mt19937_64



ll cdiv(ll a, ll b) {
	return a / b + ((a ^ b) > 0 && a % b);
}  // divide a by b rounded up
ll fdiv(ll a, ll b) {
	return a / b - ((a ^ b) < 0 && a % b);
}  // divide a by b rounded down

tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; } // set a = max(a,b)

tcT > void remDup(vector<T> &v) {  // sort and remove duplicates
	sort(all(v));
	v.erase(unique(all(v)), end(v));
}
tcTU > void safeErase(T &t, const U &u) {
	auto it = t.find(u);
	assert(it != end(t));
	t.erase(it);
}



inline namespace FileIO {
void setIn(str s) { freopen(s.c_str(), "r", stdin); }
void setOut(str s) { freopen(s.c_str(), "w", stdout); }
void setIO(str s = "") {
	cin.tie(0)->sync_with_stdio(0);  // unsync C / C++ I/O streams
	//? cout << fixed << setprecision(12);
    //? cerr << fixed << setprecision(12);
	cin.exceptions(cin.failbit);
	// throws exception when do smth illegal
	// ex. try to read letter into int
	if (sz(s)) setIn(s + ".in"), setOut(s + ".out");  // for old USACO
}
}  // namespace FileIO



//? Custom Helpers
template <typename T>
inline T gcd(T a, T b) { while (b != 0) swap(b, a %= b); return a; }

__int128 binpow(__int128 a, __int128 b) {
    __int128 res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b /= 2;
    }
    return res;
}
//? /Custom Helpers
//? Generator
int rng_int(int L, int R) { assert(L <= R);
	return uniform_int_distribution<int>(L,R)(rng);  }
ll rng_ll(ll L, ll R) { assert(L <= R);
	return uniform_int_distribution<ll>(L,R)(rng);  }
//https://www.geeksforgeeks.org/convert-a-number-from-base-a-to-base-b/
__int128 val(char c){
    if (c >= '0' && c <= '9')
        return (__int128)c - '0';
    else
        return (__int128)c - 'A' + __int128(10);
}


__int128 toDeci(string str, __int128 base){

    __int128 len = str.size();
    __int128 power = 1;
    __int128 num = 0;
    for (__int128 i = len - 1; i >= 0; i--) {
        if (val(str[i]) >= base) {
            //printf("Invalid Number");
            return -1;
        }
 
        // Update num
        num += val(str[i]) * power;
 
        // Update power
        power = power * base;
    }
 
    return num;
}

char reVal(__int128 num){
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}
__int128 atoint128_t(std::string const & in)
{
    __int128 res = 0;
    size_t i = 0;
    bool sign = false;

    if (in[i] == '-')
    {
        ++i;
        sign = true;
    }

    if (in[i] == '+')
    {
        ++i;
    }

    for (; i < in.size(); ++i)
    {
        const char c = in[i];
        if (not std::isdigit(c)) 
            throw std::runtime_error(std::string("Non-numeric character: ") + c);
        res *= 10;
        res += c - '0';
    }

    if (sign)
    {
        res *= -1;
    }

    return res;
}
string fromDeci(__int128 base,__int128 inputNum){
    string res = "";
    while (inputNum > 0) {
        res += reVal(inputNum % base);
        inputNum /= base;
    }
    reverse(res.begin(), res.end());
    return res;
}
str convertBase(string &s, __int128 a, __int128 b){
    __int128 num = toDeci(s, a);
    string ans = fromDeci(b, num);
    return ans;
}
ll solve(ll l,ll r) {
    auto sum=[&](__int128 x,__int128 lim){
        __int128 suma=0;
        FOR(i,1,lim){
            suma+=binpow(i,x);
        }
        return suma;
    };
    auto get=[&](ll x)->__int128{
        if(x<10)return 0;
        __int128 res=0,cont=1,guarda=0;
        for(__int128 i=10;i*10<=x;i*=10){
            res+=sum(cont,10);
            cont++;
        }
        str xd=ts(x);
        __int128 base=xd[0]-'0';
        res+=sum(cont,base);
        str num="";
        FOR(i,1,sz(xd)){
            if(xd[i]-'0' < base){
                num+=xd[i];
            }
            else{
                FOR(j,i,sz(xd)){
                    num+=('0'+ base -1);
                }
                break;
            }
        }   
        res+=atoint128_t(convertBase(num,base,10)) + __int128(1);
        return res;
    };
    auto xd=get(r)-get(l-1);
    dbg((ll)(get(r)), (ll)(get(l-1)));
    dbg('k'-'a','p'-'a');
    return (long long)(xd);
    
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    //cin >> t;

    for(int idx = 0; idx < t; idx++) {
        RAYA;
        RAYA;
		ll l,r;
		cin>>l>>r;
        cout<<solve(l,r)<<"\n";
    }
    RAYA;
    RAYA;

    #ifdef LOCAL
        cerr << fixed << setprecision(5);
        cerr << "\033[42m++++++++++++++++++++\033[0m\n";
        cerr << "\033[42mtime = " << time_elapsed() << "ms\033[0m\n";
        cerr << "\033[42m++++++++++++++++++++\033[0m";
    #endif
}








