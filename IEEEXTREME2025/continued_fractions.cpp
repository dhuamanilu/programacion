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

const int MOD = 998244353;
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

/**
 * Description: modular arithmetic operations 
 * Source: 
	* KACTL
	* https://codeforces.com/blog/entry/63903
	* https://codeforces.com/contest/1261/submission/65632855 (tourist)
	* https://codeforces.com/contest/1264/submission/66344993 (ksun)
	* also see https://github.com/ecnerwala/cp-book/blob/master/src/modnum.hpp (ecnerwal)
 * Verification: 
	* https://open.kattis.com/problems/modulararithmetic
 */

#pragma once

template<int MOD, int RT> struct mint {
	static const int mod = MOD;
	static constexpr mint rt() { return RT; } // primitive root for FFT
	int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
	mint():v(0) {}
	mint(ll _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
		if (v < 0) v += MOD; }
	bool operator==(const mint& o) const {
		return v == o.v; }
	friend bool operator!=(const mint& a, const mint& b) { 
		return !(a == b); }
	friend bool operator<(const mint& a, const mint& b) { 
		return a.v < b.v; }
	/*friend void re(mint& a) { ll x; re(x); a = mint(x); }
	friend str ts(mint a) { return ts(a.v); }*/
   
	mint& operator+=(const mint& o) { 
		if ((v += o.v) >= MOD) v -= MOD; 
		return *this; }
	mint& operator-=(const mint& o) { 
		if ((v -= o.v) < 0) v += MOD; 
		return *this; }
	mint& operator*=(const mint& o) { 
		v = int((ll)v*o.v%MOD); return *this; }
	mint& operator/=(const mint& o) { return (*this) *= inv(o); }
	friend mint pow(mint a, ll p) {
		mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans; }
	friend mint inv(const mint& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
		
	mint operator-() const { return mint(-v); }
	mint& operator++() { return *this += 1; }
	mint& operator--() { return *this -= 1; }
	friend mint operator+(mint a, const mint& b) { return a += b; }
	friend mint operator-(mint a, const mint& b) { return a -= b; }
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	friend mint operator/(mint a, const mint& b) { return a /= b; }
};

using mi = mint<MOD,5>; // 5 is primitive root for both common mods
using vmi = V<mi>;
using pmi = pair<mi,mi>;
using vpmi = V<pmi>;

V<vmi> scmb; // small combinations
void genComb(int SZ) {
	scmb.assign(SZ,vmi(SZ)); scmb[0][0] = 1;
	FOR(i,1,SZ) F0R(j,i+1) 
		scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
}


/**
 * Description: Basic poly ops including division. Can replace \texttt{T} with double, complex.
 * Source: https://github.com/bqi343/cp-notebook/blob/master/Implementations/content/numerical/Polynomials/Poly.h
 * 
	* https://github.com/kth-competitive-programming/kactl/blob/master/content/numerical/PolyInterpolate.h
	* https://github.com/ecnerwala/icpc-book/blob/master/content/numerical/fft.cpp
 * Verification: see FFT
 */


using T = mi; using poly = V<T>;
void remz(poly& p) { while (sz(p)&&p.bk==T(0)) p.pop_back(); }
poly REMZ(poly p) { remz(p); return p; }
poly rev(poly p) { reverse(all(p)); return p; }
poly shift(poly p, int x) { 
	if (x >= 0) p.insert(begin(p),x,0); 
	else assert(sz(p)+x >= 0), p.erase(begin(p),begin(p)-x);
	return p; 
}
poly RSZ(const poly& p, int x) { 
	if (x <= sz(p)) return poly(begin(p),begin(p)+x);
	poly q = p; q.rsz(x); return q;  }
T eval(const poly& p, T x) { // evaluate at point x
	T res = 0; R0F(i,sz(p)) res = x*res+p[i]; 
	return res; }
poly dif(const poly& p) { // differentiate
	poly res; FOR(i,1,sz(p)) res.pb(T(i)*p[i]); 
	return res; }
poly integ(const poly& p) { // integrate
	static poly invs{0,1};
	for (int i = sz(invs); i <= sz(p); ++i) 
		invs.pb(-MOD/i*invs[MOD%i]);
	poly res(sz(p)+1); F0R(i,sz(p)) res[i+1] = p[i]*invs[i+1];
	return res; 
}

poly& operator+=(poly& l, const poly& r) {
	l.rsz(max(sz(l),sz(r))); F0R(i,sz(r)) l[i] += r[i]; 
	return l; }
poly& operator-=(poly& l, const poly& r) {
	l.rsz(max(sz(l),sz(r))); F0R(i,sz(r)) l[i] -= r[i]; 
	return l; }
poly& operator*=(poly& l, const T& r) { each(t,l) t *= r; 
	return l;	 }
poly& operator/=(poly& l, const T& r) { each(t,l) t /= r; 
	return l; }
poly operator+(poly l, const poly& r) { return l += r; }
poly operator-(poly l, const poly& r) { return l -= r; }
poly operator-(poly l) { each(t,l) t *= -1; return l; }
poly operator*(poly l, const T& r) { return l *= r; }
poly operator*(const T& r, const poly& l) { return l*r; }
poly operator/(poly l, const T& r) { return l /= r;	 }
poly operator*(const poly& l, const poly& r) {
	if (!min(sz(l),sz(r))) return {};
	poly x(sz(l)+sz(r)-1); 
	F0R(i,sz(l)) F0R(j,sz(r)) x[i+j] += l[i]*r[j];
	return x;
}
poly& operator*=(poly& l, const poly& r) { return l = l*r; }

pair<poly,poly> quoRemSlow(poly a, poly b) { 
	remz(a); remz(b); assert(sz(b));
	T lst = b.bk, B = T(1)/lst; each(t,a) t *= B; 
	each(t,b) t *= B;
	poly q(max(sz(a)-sz(b)+1,0));
	for (int dif; (dif=sz(a)-sz(b)) >= 0; remz(a)) {
		q[dif] = a.bk; F0R(i,sz(b)) a[i+dif] -= q[dif]*b[i]; }
	each(t,a) t *= lst;
	return {q,a}; // quotient, remainder
}
poly operator%(const poly& a, const poly& b) { 
	return quoRemSlow(a,b).s; }
/**poly operator/(const poly& a, const poly& b) { 
	return quoRemSlow(a,b).f; }
poly a = {1,3,5,8,6,0,0,0,0}, b = {1,5,1};
ps(quoRemSlow(a,b)); a = 2*a, b = 2*b; ps(quoRemSlow(a,b));
poly gcd(poly a, poly b) { return b == poly{} ? a : gcd(b,a%b); }*/
T resultant(poly a, poly b) { // R(A,B)
	// =b_m^n*prod_{j=1}^mA(mu_j)
	// =b_m^na_n^m*prod_{i=1}^nprod_{j=1}^m(mu_j-lambda_i)
	// =(-1)^{mn}a_n^m*prod_{i=1}^nB(lambda_i)
	// =(-1)^{nm}R(B,A)
	// Also, R(A,B)=b_m^{deg(A)-deg(A-CB)}R(A-CB,B)
	int ad = sz(a)-1, bd = sz(b)-1; 
	if (bd <= 0) return bd < 0 ? 0 : pow(b.bk,ad);
	int pw = ad; a = a%b; pw -= (ad = sz(a)-1);
	return resultant(b,a)*pow(b.bk,pw)*T((bd&ad&1)?-1:1);
}








/**
 * Description: Multiply polynomials of ints for any modulus $<2^{31}$. 
 	* For XOR convolution ignore \texttt{m} within \texttt{fft}. 
 * Time: $O(N\log N)$. For $N=10^6$, conv \tilde 0.13ms, conv\_general \tilde 320ms.
 * Source: 
 	* KACTL (https://github.com/kth-competitive-programming/kactl/blob/master/content/numerical/NumberTheoreticTransform.h)
 	* https://cp-algorithms.com/algebra/fft.html
 	* https://csacademy.com/blog/fast-fourier-transform-and-variations-of-it
 	* maroonrk
 	* https://github.com/atcoder/ac-library/blob/master/atcoder/convolution.hpp
 * Verification: 
	* https://judge.yosupo.jp/problem/convolution_mod
	* SPOJ polymul, CSA manhattan, CF Perfect Encoding
	* http://codeforces.com/contest/632/problem/E
 */

tcT> void fft(V<T>& A, bool invert = 0) { // NTT
	int n = sz(A); assert((T::mod-1)%n == 0); V<T> B(n);
	for(int b = n/2; b; b /= 2, swap(A,B)) { // w = n/b'th root
		T w = pow(T::rt(),(T::mod-1)/n*b), m = 1; 
		for(int i = 0; i < n; i += b*2, m *= w) F0R(j,b) {
			T u = A[i+j], v = A[i+j+b]*m;
			B[i/2+j] = u+v; B[i/2+j+n/2] = u-v;
		}
	}
	if (invert) { reverse(1+all(A)); 
		T z = inv(T(n)); each(t,A) t *= z; }
} // for NTT-able moduli
tcT> V<T> conv(V<T> A, V<T> B) {
	if (!min(sz(A),sz(B))) return {};
	int s = sz(A)+sz(B)-1, n = 1; for (; n < s; n *= 2);
	A.rsz(n), fft(A); B.rsz(n), fft(B);
	F0R(i,n) A[i] *= B[i];
	fft(A,1); A.rsz(s); return A;
}
template<class M, class T> V<M> mulMod(const V<T>& x, const V<T>& y) {
	auto con = [](const V<T>& v) {
		V<M> w(sz(v)); F0R(i,sz(v)) w[i] = (int)v[i];
		return w; };
	return conv(con(x), con(y));
} // arbitrary moduli
tcT> V<T> conv_general(const V<T>& A, const V<T>& B) {
	using m0 = mint<(119<<23)+1,62>; auto c0 = mulMod<m0>(A,B);
	using m1 = mint<(5<<25)+1,  62>; auto c1 = mulMod<m1>(A,B);
	using m2 = mint<(7<<26)+1,  62>; auto c2 = mulMod<m2>(A,B);
	int n = sz(c0); V<T> res(n); m1 r01 = inv(m1(m0::mod)); 
	m2 r02 = inv(m2(m0::mod)), r12 = inv(m2(m1::mod));
	F0R(i,n) { // a=remainder mod m0::mod, b fixes it mod m1::mod
		int a = c0[i].v, b = ((c1[i]-a)*r01).v, 
			c = (((c2[i]-a)*r02-b)*r12).v;
		res[i] = (T(c)*m1::mod+b)*m0::mod+a; // c fixes m2::mod
	}
	return res;
}

poly mul(poly A, poly B) {
    if (!min(sz(A), sz(B))) return {};
    int s = sz(A) + sz(B) - 1, n = 1;
    while (n < s) n <<= 1;
    A.rsz(n); B.rsz(n);
    fft(A); fft(B);              
    F0R(i, n) A[i] *= B[i];
    fft(A, 1);
    A.rsz(s);
    return A;
}
poly inv(const poly& A, int NEED_N);
pair<poly,poly> quoRem(poly a, poly b) {
    remz(a); remz(b); assert(sz(b));
    if (sz(a) < sz(b)) return {poly{}, a};
    int n = sz(a)-1, m = sz(b)-1, k = n-m+1;
    poly ra = rev(a), rb = rev(b);
    poly inv_rb = inv(rb, k);               
    poly qrev = RSZ(mul(ra, inv_rb), k);    
    poly q = rev(qrev);
    poly r = a - mul(q, b);
    r = RSZ(r, m);
    remz(q); remz(r);
    return {q, r};
}









//https://github.com/bqi343/cp-notebook/blob/master/Implementations/content/numerical/Polynomials/PolyMultipoint.h
/**
 * Description: Multipoint evaluation and interpolation
 * Time: O(N\log^2 N)
 */


//#include "PolyInv.h"
/**
 * Description: computes $A^{-1}$ such that $AA^{-1}\equiv 1\pmod{x^n}$.
 	* Newton's method: If you want $F(x)=0$ and $F(Q_k)\equiv 0\pmod{x^a}$
 	* then $Q_{k+1}=Q_k-\frac{F(Q_k)}{F'(Q_k)}\pmod{x^{2a}}$ satisfies
 	* $F(Q_{k+1})\equiv 0 \pmod{x^{2a}}$. Application: if $f(n),g(n)$ are the
 	* \#s of forests and trees on $n$ nodes then 
 	* $\sum_{n=0}^{\infty}f(n)x^n=\exp\left(\sum_{n=1}^{\infty}\frac{g(n)}{n!}\right)$.
 * Time: O(N\log N)
 * Source: CF
 	* http://people.csail.mit.edu/madhu/ST12/scribe/lect06.pdf
 	* https://cp-algorithms.com/algebra/polynomial.html
 	* maroonrk's submissions ^_^
 	* if you need faster exp for some reason, see https://old.yosupo.jp/submission/36732 ...
 * Usage: vmi v={1,5,2,3,4}; ps(exp(2*log(v,9),9)); // squares v
 * Verification: https://codeforces.com/contest/438/problem/E
 	* https://codeforces.com/gym/102028/submission/77687049
 	* https://loj.ac/problem/6703 (MultipointEval)
 */
/// WARNING: lots of sketchy optimizations to improve constant factors of calls to FFT ...
/// there are much simpler versions of functions below, but they are slower ...

void double_inverse_given(poly& A_inv, poly a, 
		const poly& a_inv) {
	int N = sz(A_inv);
	F0R(i,2*N) a[i] *= a_inv[i];
	fft(a,1); F0R(i,N) a[i] = 0; 
	/// now a represents 1+stuff_{N..3*N-2}, we only care about stuff_{N..2*N-1} 
	/// so we zero out the rest
	fft(a); F0R(i,2*N) a[i] *= a_inv[i];
	fft(a,1); FOR(i,N,2*N) A_inv.pb(-a[i]);
}

void double_inverse(const poly& A, poly& A_inv) { 
	/// given first 2*N terms of A and N terms of A_inv, extend A_inv
	/// add terms N...2*N-1 of -A_inv^2A to A_inv
	int N = sz(A_inv);
	poly f = RSZ(A,2*N); fft(f); // first 2N terms of A
	poly g = RSZ(A_inv,2*N); fft(g);
	double_inverse_given(A_inv,f,g);
}

// A_inv such that A*A_inv = 1
poly inv(const poly& A, int NEED_N) { assert(A[0] != 0);
	// F(Q)=1/Q
	// Q-F(Q)/F'(Q)=Q-(1/Q-A)/(-Q^{-2})
	// =2Q-Q^2A=Q+Q(1-QA)
	poly A_inv{1/A[0]};
	while (sz(A_inv) < NEED_N) double_inverse(A,A_inv);
	return RSZ(A_inv,NEED_N);
}

// e^{result}=A
poly log(poly A, int N) { assert(A[0] == 1); 
	// ln A = integral(A'/A)
	return integ(RSZ(mul(dif(A),inv(A,N-1)),N-1)); }

// A_sqrt^2=A
poly sqrt(const poly& A, int NEED_N) { assert(A[0] == 1); 
	// F(Q)=Q^2-A
	// Q-F(Q)/F'(Q)=Q-(Q^2-A)/(2Q)
	// =1/2(Q+A/Q)
	const T i2 = T(1)/T(2);
	poly A_sqrt{1}, A_sqrt_inv{1},a_sqrt{1};
	auto value_at = [&](int i) -> T { return i<sz(A)?A[i]:0; };
	for (int N = 1; N < NEED_N; N *= 2) {
		F0R(i,N) a_sqrt[i] *= a_sqrt[i]; // z is transform of Q^2
		fft(a_sqrt,1); poly delta(2*N); // set delta = Q^2-A
		F0R(i,N) delta[N+i] = a_sqrt[i]-value_at(i)-value_at(N+i);
		fft(delta); 
		poly a_sqrt_inv = RSZ(A_sqrt_inv,2*N);
		fft(a_sqrt_inv); F0R(i,2*N) delta[i] *= a_sqrt_inv[i];
		fft(delta,1); FOR(i,N,2*N) A_sqrt.pb(-i2*delta[i]);
		// get terms of (Q^2-A)/2Q
		if (2*N >= NEED_N) break;
		a_sqrt = A_sqrt; fft(a_sqrt);
		double_inverse_given(A_sqrt_inv,a_sqrt,a_sqrt_inv);
	}
	return RSZ(A_sqrt,NEED_N);
}

// e^A
poly exp(const poly& A, int NEED_N) { assert(A[0] == 0);
	// F(Q)=ln(Q)-A
	// Q-F(Q)/F'(Q)=Q-(ln(Q)-A)/(1/Q)
	// =Q*(1+A-ln(Q))=Q+Q*(A-ln(Q))
	auto value_at = [&](int i) -> T { return i<sz(A)?A[i]:0; };
	auto conv_given = [&](const poly& a, poly b) {
		b.rsz(sz(a)); fft(b); // fft already applied to a
		F0R(i,sz(b)) b[i] *= a[i];
		fft(b,1); return b; };
	poly A_exp{1}, A_inv{1};
	for (int N = 1; N < NEED_N; N *= 2) { // sz(A_exp) = N
		poly a_exp = RSZ(A_exp,2*N); fft(a_exp);
		if (N > 1) {
			poly a_inv_small = RSZ(A_inv,2*N); fft(a_inv_small);
			F0R(i,2*N) a_inv_small[i] *= a_inv_small[i]*a_exp[i];
			fft(a_inv_small,1);
			FOR(i,N/2,N) A_inv.pb(-a_inv_small[i]);
		}
		poly a_inv = RSZ(A_inv,2*N); fft(a_inv);
		poly ln = conv_given(a_inv,dif(A_exp));
		poly a_inv_exp(2*N); 
		F0R(i,2*N) a_inv_exp[i] = a_inv[i]*a_exp[i];

		poly a_dif = RSZ(dif(RSZ(A,N)),2*N); fft(a_dif);
		F0R(i,2*N) a_inv_exp[i] *= a_dif[i];
		fft(a_inv_exp,1); FOR(i,N,2*N) ln[i] -= a_inv_exp[i];
		ln.pop_back(); ln = integ(ln);

		poly A_minus_ln(N); 
		F0R(i,N) A_minus_ln[i] = value_at(i+N)-ln[i+N];
		poly prod = conv_given(a_exp,A_minus_ln); // conv(N,N)
		FOR(i,N,2*N) A_exp.pb(prod[i-N]);
	} 
	return RSZ(A_exp,NEED_N);
}









//#include "PolyConv.h"
//https://github.com/bqi343/cp-notebook/blob/master/Implementations/content/numerical/Polynomials/PolyConv.h
/**
 * Description: Multiply small polys directly, otherwise use FFT.
 * Source: KACTL, https://cp-algorithms.com/algebra/fft.html
 */

bool small(const poly& a, const poly& b) { // multiply directly
	return min(sz(a),sz(b)) <= 60; }
// vmi smart(const vmi& a, const vmi& b) { return mul(a,b); }
// vl smart(const vl& a, const vl& b) {
// 	auto X = mul(vcd(all(a)),vcd(all(b)));
// 	vl x(sz(X)); F0R(i,sz(X)) x[i] = round(X[i].real());
// 	return x; }
poly conv(const poly& a, const poly& b) {
	return small(a,b) ? a*b : mul(a,b); } 



//https://github.com/bqi343/cp-notebook/blob/master/Implementations/content/numerical/Polynomials/PolyMultipoint.h
void segProd(V<poly>& stor, poly& v, int ind, int l, int r) { // v -> places to evaluate at
	if (l == r) { stor[ind] = {-v[l],1}; return; }
	int m = (l+r)/2; segProd(stor,v,2*ind,l,m); segProd(stor,v,2*ind+1,m+1,r);
	stor[ind] = conv(stor[2*ind],stor[2*ind+1]);
}
void evalAll(V<poly>& stor, poly& res, poly v, int ind = 1) {
	v = quoRem(v,stor[ind]).s;
	if (sz(stor[ind]) == 2) { res.pb(sz(v)?v[0]:0); return; }
	evalAll(stor,res,v,2*ind); evalAll(stor,res,v,2*ind+1);
}

// evaluate polynomial v at points in p
poly multiEval(poly v, poly p) {
	V<poly> stor(4*sz(p)); segProd(stor,p,1,0,sz(p)-1);
	poly res; evalAll(stor,res,v); return res; }

poly combAll(V<poly>& stor, poly& dems, int ind, int l, int r) {
	if (l == r) return {dems[l]};
	int m = (l+r)/2;
	poly a = combAll(stor,dems,2*ind,l,m), b = combAll(stor,dems,2*ind+1,m+1,r);
	return conv(a,stor[2*ind+1])+conv(b,stor[2*ind]);
}
poly interpolate(V<pair<T,T>> v) {
	int n = sz(v); poly x; each(t,v) x.pb(t.f);
	V<poly> stor(4*n); segProd(stor,x,1,0,n-1);
	poly dems; evalAll(stor,dems,dif(stor[1]));
	F0R(i,n) dems[i] = v[i].s/dems[i];
	return combAll(stor,dems,1,0,n-1);
}





//https://www.cnblogs.com/zbh2047/p/8569928.html

void solve(){
    ll n,m;
    cin>>n>>m;
    vmi a(n);
    mi sum = 0;
    for(ll i = 0 ; i < n; i++){
        ll x;
        cin>>x;
        a[i]=mi(x);
        sum += a[i];
    }
    vmi neg(n);
    for(ll i = 0 ; i < n; i++){
        neg[i]= -a[i];
    }
    auto product_poly_from_points=[](poly & roots){
        ll tam = roots.size();
        if (!tam) return poly{T(1)};
        V<poly> stor(4*tam);
        segProd(stor, roots, 1, 0, tam-1);
        return stor[1]; 
    };
    poly F = product_poly_from_points(neg);
    poly Fp = dif(F);
    mi A = 1 , B = 0 , C = 0 , D = 1;
    vmi base(m);
    vl isLinear(m);
    vmi values , pts;
    for(ll i = 0 ; i < m; i++){
        ll type;
        cin>>type;
        if(type == 1){
            ll x;
            cin>>x;
            mi val = mi(x);
            A += val * C;
            B += val * D;

        }
        else{
            swap(A ,C);
            swap(B , D);
        }

        if(C!=mi(0)){
            mi invC = inv(C);
            mi y = D *invC;
            base[i] = A * invC * mi(n); 
            mi k = (B - A * y) * invC;
            values.push_back(k);
			pts.push_back(y);
			isLinear[i] = 0;
        }
        else{
            base[i] = (A * sum + B * mi(n)) * inv(D);
			isLinear[i] = 1;
        }
    }
    vmi Fvals, Fpvals;
	if (sz(pts)) {
		Fvals  = multiEval(F,  pts);
		Fpvals = multiEval(Fp, pts);
	}
    ll xd = 0;
    for(ll j = 0 ; j < m; j++){
        if (isLinear[j]) {
			cout << base[j].v << "\n";
		} else {
			mi t = Fpvals[xd] / Fvals[xd];         
			mi ans = base[j] + values[xd] * t;     
			cout << ans.v << "\n";
			xd++;
		}
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    //cin>>t;
    while(t--) solve();
}