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
const int MX = 100001;
const int N=1000+3;

void solve(){
    ll n,m,x;
    cin>>n>>m>>x;
    vector<pair<ll,char>> a(m);
    FOR(i,0,m){
    	cin>>a[i].f>>a[i].se;
    }
    vector<vector<bool>> dp(m+1,vector<bool>(n+1,0));
    dp[0][x]=true;
    FOR1(i,1,m){
    	ll dis=a[i-1].f;
    	char dire=a[i-1].se;
    	FOR1(j,1,n){
    		
    		//clockwise
    		
    		if(dire=='0'){
    			if(j>dis && dp[i-1][j-dis]){
    				dp[i][j]=true;
    			}
    			if(n+j-dis<=n && n+j>dis && dp[i-1][n+j-dis]){
    				dp[i][j]=true;
    			}
    		}
    		else if(dire=='1'){
    			if(j+dis<=n && dp[i-1][j+dis]){
    				dp[i][j]=true;
    			}	
    			else if(j+dis>n && dp[i-1][j+dis-n]){
    				dp[i][j]=true;
    			}
    		}
    		else{
    			if(dp[i-1][j]){
    				ll ind=j+dis;
    				if(ind>n) ind-=n;
    				if(ind<0) ind+=n;
    				dp[i][ind]=true;
    				
    				
    				ll ind2=j+n-dis;
    				if(ind2>n) ind2-=n;
    				if(ind2<0) ind2+=n;
    				dp[i][ind2]=true;
    			}
    		}
    	}
    }
    vll ans;
    FOR1(i,1,n){
    	if(dp[m][i]){
    		ans.pb(i);
    	}
    }
    /*for(auto & e  :dp){
    	dbg(e);
    }
    dbg("----------");*/
    cout<<(ll)ans.size()<<"\n";
    for(auto & e:ans){
    	cout<<e<<" ";
    }
    cout<<"\n";
    
    
    
    
    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}








