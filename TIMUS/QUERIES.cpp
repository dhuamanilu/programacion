#include <bits/stdc++.h>
using namespace std;



#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)     0
    #define chk(...)     0

    #define RAYA         0
#endif



const auto beg_time = std::chrono::high_resolution_clock::now();
double time_elapsed() { return chrono::duration<double>(std::chrono::high_resolution_clock::now() - beg_time) .count(); }



// building blocks
using ll  = long long;
using db  = long double;
using str = string;

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
#define f  first
#define s  second



#define tcT template <class T
#define tcTU tcT, class U

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

using vvi = V<vi>;
using vvl = V<vl>;
using vvb = V<vb>;

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

#define lb lower_bound
#define ub upper_bound



// loops
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)
#define each(a, x) for (auto &a : x)



//? Template
const int MOD = 1e9 + 7;
const int MX = (int)2e5 + 5;
const ll BIG = 1e18;  //? not too close to LLONG_MAX
const db PI = acos((db)-1);
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};  //? for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());



ll cdiv(ll a, ll b) {
	return a / b + ((a ^ b) > 0 && a % b);
}  // divide a by b rounded up
ll fdiv(ll a, ll b) {
	return a / b - ((a ^ b) < 0 && a % b);
}  // divide a by b rounded down

tcT > bool ckmin(T &a, const T &b) {
	return b < a ? a = b, 1 : 0;
}  // set a = min(a,b)
tcT > bool ckmax(T &a, const T &b) {
	return a < b ? a = b, 1 : 0;
}  // set a = max(a,b)
//? https://codeforces.com/contest/2000/submission/276943782
//? 0-indexed
//? [l, r]

class SegmentTree {
private:
    std::vector<int> seg;
    std::vector<int> lazy;
    std::vector<int> arr;
    int n;

    void build(int node, int st, int en) {
        if (st == en) {
            seg[node] = arr[st];
            return;
        }

        int mid = (st + en) / 2;

        // Llamada recursiva para el hijo izquierdo
        build(2 * node, st, mid);

        // Llamada recursiva para el hijo derecho
        build(2 * node + 1, mid + 1, en);

        // Actualización del nodo padre con los valores de los hijos
        seg[node] = seg[2 * node] + seg[2 * node + 1];
    }

    void update(int node, int st, int en, int l, int r, int val) {
        if (lazy[node] != 0) { // Si el nodo es "lazy", lo actualiza
            seg[node] += (en - st + 1) * lazy[node];

            if (st != en) { // Si los hijos existen, los marca como "lazy"
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0; // Ya no es "lazy"
        }

        if (en < l || st > r) { // Caso 1: fuera del rango
            return;
        }

        if (st >= l && en <= r) { // Caso 2: completamente dentro del rango
            seg[node] += (en - st + 1) * val;
            if (st != en) {
                lazy[2 * node] += val; // Marca a los hijos como "lazy"
                lazy[2 * node + 1] += val;
            }
            return;
        }

        // Caso 3: parcialmente dentro del rango
        int mid = (st + en) / 2;

        // Llamada recursiva para actualizar el hijo izquierdo
        update(2 * node, st, mid, l, r, val);
        // Llamada recursiva para actualizar el hijo derecho
        update(2 * node + 1, mid + 1, en, l, r, val);

        // Actualización del nodo padre con los valores de los hijos
        seg[node] = seg[2 * node] + seg[2 * node + 1];
    }

    int query(int node, int st, int en, int l, int r) {
        if (lazy[node] != 0) { // Si el nodo es "lazy", lo actualiza
            seg[node] += (en - st + 1) * lazy[node];
            if (st != en) { // Verifica si los hijos existen
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0; // Ya no es "lazy"
        }

        if (en < l || st > r) { // Caso 1: fuera del rango
            return 0;
        }

        if (l <= st && en <= r) { // Caso 2: completamente dentro del rango
            return seg[node];
        }

        int mid = (st + en) / 2;

        // Consulta del hijo izquierdo
        int q1 = query(2 * node, st, mid, l, r);

        // Consulta del hijo derecho
        int q2 = query(2 * node + 1, mid + 1, en, l, r);

        return q1 + q2;
    }

public:
    SegmentTree(int size, std::vector<int>& elements) {
        n = size;
        arr = elements;
        seg.resize(4 * n);
        lazy.resize(4 * n, 0);
        build(1, 0, n - 1);
    }
	// Constructor sin arreglo, inicializa todo a cero
    SegmentTree(int size) {
        n = size;
        arr.assign(n, 0); // Inicializa el arreglo con ceros
        seg.resize(4 * n);
        lazy.resize(4 * n, 0);
        build(1, 0, n - 1);
    }
    void update(int l, int r, int val) {
        update(1, 0, n - 1, l, r, val);
    }

    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

void solve() {
    ll n,q;
    cin >> n >> q;
    vl p(n);
    SegmentTree a(n);
    each(x, p) {
        cin >> x;
        x--;
    }
    dbg(n,q,p);
    FOR(i,0,q) {
        ll type;
        cin >> type;
        //dbg(type);
        if(type==0) {
            ll l,r,c;
            cin >> l >> r >>c;
            //dbg(l,r,c);
            l--, r--;
            a.update(l,r,c);
        }
        else if(type==1){
            ll l,r,c;
            cin >> l >> r >>c;
            //dbg(l,r,c);
            l--, r--;
            FOR(j,l,r+1) {
                //a[p[j]] += c;
                a.update(p[j],p[j],c);
            }
        }
        else if(type==2){
            ll l,r;
            cin >> l >> r;
            //dbg(l,r);
            l--, r--;
            ll ans = a.query(l,r);
            cout << ans << '\n';
        }
        else{
            ll l,r;
            cin >> l >> r;
            //dbg(l,r);
            l--, r--;
            ll ans = 0;
            FOR(j,l,r+1) {
                ans += a.query(p[j],p[j]);
            }
            cout << ans << '\n';
        }
        
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int t = 1; //! cin >> t;
    for(int i = 0; i < t; i++) {
        RAYA;
        RAYA;
        solve();
    }
    RAYA;
    RAYA;

    #ifdef LOCAL
        cerr << fixed << setprecision(5);
        cerr << "\033[42m++++++++++++++++++++\033[0m\n";
        cerr << "\033[42mtime = " << time_elapsed() << "ms\033[0m\n";
        cerr << "\033[42m++++++++++++++++++++\033[0m\n";
    #endif
}