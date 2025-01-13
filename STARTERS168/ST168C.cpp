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

//https://www.geeksforgeeks.org/count-of-distinct-numbers-in-an-array-in-a-range-for-online-queries-using-merge-sort-tree/
// Function to merge the right
// and the left tree
void merge(vector<vector<int>> & tree, int treeNode)
{
    int len1 = tree[2 * treeNode].size();
    int len2 = tree[2 * treeNode + 1].size();
    int index1 = 0, index2 = 0;
 
    // Fill this array in such a
    // way such that values
    // remain sorted similar to mergesort
    while (index1 < len1 && index2 < len2) {
 
        // If the element on the left part
        // is greater than the right part
        if (tree[2 * treeNode][index1]
            > tree[2 * treeNode + 1][index2]) {
 
            tree[treeNode].push_back(
                tree[2 * treeNode + 1][index2]);
            index2++;
        }
        else {
            tree[treeNode].push_back(
                tree[2 * treeNode][index1]);
            index1++;
        }
    }
 
    // Insert the leftover elements
    // from the left part
    while (index1 < len1) {
        tree[treeNode].push_back(
            tree[2 * treeNode][index1]);
        index1++;
    }
 
    // Insert the leftover elements
    // from the right part
    while (index2 < len2) {
        tree[treeNode].push_back(
            tree[2 * treeNode + 1][index2]);
        index2++;
    }
    return;
}
 
// Recursive function to build
// segment tree by merging the
// sorted segments in sorted way
void build(vector<vector<int>> &tree, vector<int> &arr, int start, int end,
           int treeNode)
{
    // Base case
    if (start == end) {
        tree[treeNode].push_back(arr[start]);
        return;
    }
    int mid = (start + end) / 2;
 
    // Building the left tree
    build(tree, arr, start, mid, 2 * treeNode);
 
    // Building the right tree
    build(tree, arr, mid + 1, end, 2 * treeNode + 1);
 
    // Merges the right tree
    // and left tree
    merge(tree, treeNode);
    return;
}
 
// Function similar to query() method
// as in segment tree
int query(vector<vector<int>> &tree, int treeNode, int start,
          int end, int left, int right)
{
 
    // Current segment is out of the range
    if (start > right || end < left) {
        return 0;
    }
    // Current segment completely
    // lies inside the range
    if (start >= left && end <= right) {
 
        // as the elements are in sorted order
        // so number of elements greater than R
        // can be find using binary
        // search or upper_bound
        return tree[treeNode].end()
               - upper_bound(tree[treeNode].begin(),
                             tree[treeNode].end(), right);
    }
 
    int mid = (start + end) / 2;
 
    // Query on the left tree
    int op1 = query(tree, 2 * treeNode, start, mid, left,
                    right);
    // Query on the Right tree
    int op2 = query(tree, 2 * treeNode + 1, mid + 1, end,
                    left, right);
    return op1 + op2;
}
ll solve(vi &a) {
	ll n=a.size();
	map<ll,ll> m;
	each(e,a)m[e]++;
	vl first(n+1,-1),last(n+1,-1);
	FOR(i,0,n){
		if(first[a[i]]==-1) first[a[i]]=i;
		last[a[i]]=i;
	}
	
	vi next_right(n);
    // Initialising the tree
    vector<vector<int>> tree(4*n);
 
    map<int, int> ump;

    for (int i = n - 1; i >= 0; i--) {
        if (ump[a[i]] == 0) {
            next_right[i] = n;
            ump[a[i]] = i;
        }
        else {
            next_right[i] = ump[a[i]];
            ump[a[i]] = i;
        }
    }
    // building the mergesort tree
    // by using next_right array
    build(tree, next_right, 0, n - 1, 1);
	/*
		// first query
		int left1 = 0;
		int right1 = 2;
		ans = query(tree, 1, 0, n - 1, left1, right1);

	*/
	ll ans=0;
	dbg(first,last);
	each(e,m){
		if(e.s==1) continue;
		ans+=query(tree,1,0,n-1,first[e.f],last[e.f]);
	}
	
	return min(ans,(ll)m.size());
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;

    for(int idx = 0; idx < t; idx++) {
        RAYA;
        RAYA;
		ll n;
		cin>>n;
		vi a(n);
		each(e,a)cin>>e;
        cout<<solve(a)<<"\n";
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








