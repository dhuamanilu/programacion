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
struct Cell3D {
    int ell, y, x;
};
const map<char, tuple<int,int,int>> moveDelta {
    {'u', {0, -1,  0}},
    {'d', {0, +1,  0}},
    {'f', {+1, 0,  0}},
    {'b', {-1, 0,  0}},
    {'r', {0,  0, +1}},
    {'l', {0,  0, -1}}
};
vector<Cell3D> buildBand(int S, int startEll, int startY, int startX, const string &seq) {
    vector<Cell3D> path;
    path.push_back({startEll, startY, startX}); 

    int curEll = startEll, curY = startY, curX = startX;
    for (char c : seq) {
        auto [de, dy, dx] = moveDelta.at(c);
        curEll += de;
        curY   += dy;
        curX   += dx;
        path.push_back({curEll, curY, curX});
    }
    if (!path.empty() && path.front().ell == path.back().ell &&
                         path.front().y   == path.back().y   &&
                         path.front().x   == path.back().x) {
        path.pop_back();
    }

    return path;
}
bool areLinked(vector<Cell3D> &band1, vector<Cell3D> &band2) {
    int minE1=INT_MAX, maxE1=INT_MIN;
    int minY1=INT_MAX, maxY1=INT_MIN;
    int minX1=INT_MAX, maxX1=INT_MIN;

    for (auto &c : band1) {
        minE1 = min(minE1, c.ell);
        maxE1 = max(maxE1, c.ell);
        minY1 = min(minY1, c.y);
        maxY1 = max(maxY1, c.y);
        minX1 = min(minX1, c.x);
        maxX1 = max(maxX1, c.x);
    }
    int minE2=INT_MAX, maxE2=INT_MIN;
    int minY2=INT_MAX, maxY2=INT_MIN;
    int minX2=INT_MAX, maxX2=INT_MIN;

    for (auto &c : band2) {
        minE2 = min(minE2, c.ell);
        maxE2 = max(maxE2, c.ell);
        minY2 = min(minY2, c.y);
        maxY2 = max(maxY2, c.y);
        minX2 = min(minX2, c.x);
        maxX2 = max(maxX2, c.x);
    }
    bool noOverlapEll = (maxE1 < minE2) || (maxE2 < minE1);
    bool noOverlapY   = (maxY1 < minY2) || (maxY2 < minY1);
    bool noOverlapX   = (maxX1 < minX2) || (maxX2 < minX1);
    if (noOverlapEll || noOverlapY || noOverlapX) {
        return false; 
    }
    return true; 
}

int countAbove(const vector<Cell3D> &A, const vector<Cell3D> &B) {
    unordered_map<long long, vector<int>> bMap; 
    bMap.reserve(B.size());

    auto pack = [&](int e, int x) {
        return (long long)e * 10000 + (long long)x;
    };

    for (auto &c : B) {
        long long key = pack(c.ell, c.x);
        bMap[key].push_back(c.y);
    }
    for (auto &kv : bMap) {
        auto &v = kv.second;
        sort(v.begin(), v.end());
    }

    int result = 0;

    for (auto &cellA : A) {
        long long key = pack(cellA.ell, cellA.x);
        if (!bMap.count(key)) continue;
        auto &ys = bMap[key];
        auto it = upper_bound(ys.begin(), ys.end(), cellA.y);
        result += (int)(ys.end() - it);
    }
    return result;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    //cin >> t;

    for(int idx = 0; idx < t; idx++) {
        RAYA;
        RAYA;
		int s; 
        cin >> s;
        int e1, y1, x1;
        cin >> e1 >> y1 >> x1;
        str seq1;
        cin >> seq1;
        vector<Cell3D> band1 = buildBand(s, e1, y1, x1, seq1);
        int e2, y2, x2;
        cin >> e2 >> y2 >> x2;
        str seq2;
        cin >> seq2;
        vector<Cell3D> band2 = buildBand(s, e2, y2, x2, seq2);
        if (areLinked(band1, band2)) {
            cout << "Impossible\n";
            return 0;
        }
        int above1 = countAbove(band1, band2); 
        int above2 = countAbove(band2, band1); 
        cout << max(above1, above2) << "\n";
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








