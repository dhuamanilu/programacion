//? #pragma GCC optimize ("Ofast")
//? #pragma GCC target ("avx,avx2")
//! #pragma GCC optimize ("trapv")
//#undef _GLIBCXX_DEBUG //? for Stress Testing
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

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
//? /Custom Helpers
//? Generator
int rng_int(int L, int R) { assert(L <= R);
	return uniform_int_distribution<int>(L,R)(rng);  }
ll rng_ll(ll L, ll R) { assert(L <= R);
	return uniform_int_distribution<ll>(L,R)(rng);  }
//? /Generator
void update(vi  &Tree, int idx, int s,
            int e, int pos, int X)
{
    // If current node is a
    // leaf nodes
    if (s == e) {
 
        // Update Tree[idx]
        Tree[idx] += X;
    }
 
    else {
 
        // Divide segment tree into left
        // and right subtree
        int m = (s + e) / 2;
 
        // Check if pos lies in left subtree
        if (pos <= m) {
 
            // Search pos in left subtree
            update(Tree, 2 * idx, s, m, pos, X);
        }
        else {
 
            // Search pos in right subtree
            update(Tree, 2 * idx + 1, m + 1, e,
                   pos, X);
        }
 
        // Update Tree[idx]
        Tree[idx]
            = Tree[2 * idx] + Tree[2 * idx + 1];
    }
}
 
// Function to find the sum from
// elements in the range [0, X]
ll sum(vi &Tree, int idx, int s,
        int e, int ql, int qr)
{
    // Check if range[ql, qr] equals
    // to range [s, e]
    if (ql == s && qr == e)
        return Tree[idx];
 
    if (ql > qr)
        return 0;
 
    // Divide segment tree into
    // left subtree and
    // right subtree
    int m = (s + e) / 2;
 
    // Return sum of elements in the range[ql, qr]
    return sum(Tree, 2 * idx, s, m, ql, min(m, qr))
           + sum(Tree, 2 * idx + 1, m + 1, e,
                 max(ql, m + 1), qr);
}
 
// Function to find Xth element
// in the array
ll getElement(vi & Tree, int X, int N){
    // Print element at index x
    return sum(Tree, 1, 0, N - 1, 0, X);
}
 
// Function to update array elements
// in the range [L, R]
void range_Update(vi &Tree, int L,
                  int R, int X, int N)
{
 
    // Update arr[l] += X
    update(Tree, 1, 0, N - 1, L, X);
 
    // Update arr[R + 1] += X
    if (R + 1 < N)
        update(Tree, 1, 0, N - 1, R + 1, -X);
}
pair<pl,ll> solve(vpl &a,vector<pair<char,ll>> &d,ll sx,ll sy) {
	ll n=a.size();
	sor(a);
	vpl b;
	each(e,a){
		b.pb(mp(e.s,e.f));
	}
	sor(b);
	//orden de a
	vi tree(4*n+5,0);
	//orden de b
	vi tree2(4*n+5,0);
	dbg(a);
	each(e,d){
		ll newX=sx,newY=sy;
		if(e.f=='U')newY+=e.s;
		else if(e.f=='D')newY-=e.s;
		else if(e.f=='L')newX-=e.s;
		else if(e.f=='R')newX+=e.s;
		dbg(sx,sy,newX,newY);
		if(sx==newX){
			ll pos=lower_bound(all(a),mp(sx,sy))-a.begin();
			ll pos2=upper_bound(all(a),mp(newX,newY))-a.begin()-1;
			dbg(pos,pos2);
			if(pos<=pos2){
				range_Update(tree,pos,pos2,1,n);
			}
		}
		else{
			assert(sy==newY);
			ll pos=lower_bound(all(b),mp(sy,sx))-b.begin();
			ll pos2=upper_bound(all(b),mp(newY,newX))-b.begin()-1;
			dbg(b,pos,pos2);
			if(pos<=pos2){
				range_Update(tree2,pos,pos2,1,n);
			}
		}
		sx=newX;
		sy=newY;
	}
	map<pl,ll> seen;
	FOR(i,0,n){
		if(getElement(tree,i,n)!=0){
			seen[a[i]]++;
		}
		if(getElement(tree2,i,n)!=0){
			seen[mp(b[i].s,b[i].f)]++;
		}
	}
	return mp(mp(sx,sy),sz(seen));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    //cin >> t;

    for(int idx = 0; idx < t; idx++) {
        RAYA;
        RAYA;
		ll n,m,sx,sy;
		cin>>n>>m>>sx>>sy;
		vpl a(n);
		each(e,a)cin>>e.f>>e.s;
		vector<pair<char,ll>> d(m);
		each(e,d)cin>>e.f>>e.s;
        auto xd =solve(a,d,sx,sy);
		cout<<xd.f.f<<" "<<xd.f.s<<" "<<xd.s<<"\n";
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








