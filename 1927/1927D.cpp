#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map <ll,ll> mll;
typedef vector <pair<ll,ll>> vpll;
typedef priority_queue<ll> pq;
#define FOR(i, a, b) for (long long i=a; i<(b); i++)
#define FOR1(i, a, b) for (long long i=a; i<=(b); i++)
#define mp make_pair
#define pb push_back
#define f first
#define se second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
#ifdef LOCAL
	#define n_l '\n'
	#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; cout << to_string(__VA_ARGS__) << endl
	template <typename T, size_t N> int SIZE(const T (&t)[N]){ return N; } template<typename T> int SIZE(const T &t){ return t.size(); } string to_string(const string s, int x1=0, int x2=1e9){ return '"' + ((x1 < s.size()) ? s.substr(x1, x2-x1+1) : "") + '"'; } string to_string(const char* s) { return to_string((string) s); } string to_string(const bool b) { return (b ? "true" : "false"); } string to_string(const char c){ return string({c}); } template<size_t N> string to_string(const bitset<N> &b, int x1=0, int x2=1e9){ string t = ""; for(int __iii__ = min(x1,SIZE(b)),  __jjj__ = min(x2, SIZE(b)-1); __iii__ <= __jjj__; ++__iii__){ t += b[__iii__] + '0'; } return '"' + t + '"'; } template <typename A, typename... C> string to_string(const A (&v), int x1=0, int x2=1e9, C... coords); int l_v_l_v_l = 0, t_a_b_s = 0; template <typename A, typename B> string to_string(const pair<A, B> &p) { l_v_l_v_l++; string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; l_v_l_v_l--; return res; } template <typename A, typename... C> string to_string(const A (&v), int x1, int x2, C... coords) { int rnk = rank<A>::value; string tab(t_a_b_s, ' '); string res = ""; bool first = true; if(l_v_l_v_l == 0) res += n_l; res += tab + "["; x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v)); auto l = begin(v); advance(l, x1); auto r = l; advance(r, (x2-x1) + (x2 < SIZE(v))); for (auto e = l; e != r; e = next(e)) { if (!first) { res += ", "; } first = false; l_v_l_v_l++; if(e != l){ if(rnk > 1) { res += n_l; t_a_b_s = l_v_l_v_l; }; } else{ t_a_b_s = 0; } res += to_string(*e, coords...); l_v_l_v_l--; } res += "]"; if(l_v_l_v_l == 0) res += n_l; return res; } void dbgm(){;} template<typename Heads, typename... Tails> void dbgm(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgm(T...); }
	#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgm(__VA_ARGS__); cout << endl
#else
	#define dbg(...)
	#define dbgm(...)
#endif
const int MOD = 1000000007;
const char nl = '\n';
const int MAXN=200005;
const int N=1000+3;

int lg[MAXN+1];

int f(int a,int b){
	return min(a,b);
}
int f2(int a,int b){
	return max(a,b);
}
int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}
void solve(){
    ll n;
    cin>>n;
    vector<int> a(n);
    
    int elmax=INT_MIN;
    FOR(i,0,n){
    	cin>>a[i];
    	elmax=max(elmax,a[i]);
    }
    map<int,vector<int>> guarda;
    FOR(i,0,n){
    	guarda[a[i]].pb(i);
    }
    ll k=log2_floor(n)+1;
    int stmin[k + 1][n+1];
	int stmax[k + 1][n+1];
    std::copy(a.begin(), a.end(), stmin[0]);
	
	for (int i = 1; i <= k; i++)
	    for (int j = 0; j + (1 << i) <= n; j++)
	        stmin[i][j] = f(stmin[i - 1][j], stmin[i - 1][j + (1 << (i - 1))]);
	        
	std::copy(a.begin(), a.end(), stmax[0]);
	
	for (int i = 1; i <= k; i++)
	    for (int j = 0; j + (1 << i) <= n; j++)
	        stmax[i][j] = f2(stmax[i - 1][j], stmax[i - 1][j + (1 << (i - 1))]);
    

    int q;
    cin>>q;
    //dbg(guarda);
    FOR(iter,0,q){
    	int l,r;
    	cin>>l>>r;
    	l--;
    	r--;
    	/* int i = lg[R - L + 1];
		int minimum = min(st[i][L], st[i][R - (1 << i) + 1]); */
    	int i1=lg[r-l+1];
    	int mini=min(stmin[i1][l], stmin[i1][r - (1ll << i1) + 1]);
    	int i2=lg[r-l+1];
    	int maxi=max(stmax[i2][l], stmax[i2][r - (1ll << i2) + 1]);
    	
    	if(maxi==mini){
    		cout<<"-1 -1\n";
    	}
    	else{
    		auto idx=lower_bound(guarda[mini].begin
    		(),guarda[mini].end(),l);
    		auto idy=lower_bound(guarda[maxi].begin(),guarda
    		[maxi].end(),l);
    		assert(idx!=guarda[mini].end() && idy!=
    		guarda[maxi].end());
    		cout<<(*idx)+1<<" "<<(*idy)+1<<"\n";
    	}
    }
    cout<<"\n";
    
    
    
    
    
    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    lg[1] = 0;
	for (int i = 2; i <= MAXN; i++)
    	lg[i] = lg[i/2] + 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}








