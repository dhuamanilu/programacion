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
pair<ll,ll> newPos(char d,ll row,ll col){
	if(d=='L'){
		col--;
	}
	else if(d=='R'){
		col++;
	}
	else if(d=='U'){
		row--;
	}
	else{
		row++;
	}
	return mp(row,col);
}
bool isValid(ll x,ll y,ll h,ll w){
	return x>=0 && x<h && y>=0 && y<w;	
}
void solve(){
    ll h,w,n;
    cin>>h>>w>>n;
   	string t;
   	cin>>t;
   	vector<vll> a(h,vll(w));
    FOR(i,0,h){
    	FOR(j,0,w){
    		char x;
    		cin>>x;
    		// mar 1
    		if(x=='#'){
    			a[i][j]=1;
    		}
    		else a[i][j]=0;
    	}
    }
    ll ans=0;
    FOR(i,0,h){
    	FOR(j,0,w){
    		ll x=i,y=j;
    		bool ok=true;
    		if(a[x][y]==1) continue;
    		FOR(iter,0,n){
    			
    			auto pos=newPos(t[iter],x,y);
    			x=pos.f;
    			y=pos.se;
    			if(isValid(x,y,h,w) && a[x][y]==0){
    				
    			}
    			else{
    				ok=false;
    				break;
    			}
    		}
    		/*if(isValid(x,y,h,w) && a[x][y]==0){
    				
			}
			else{
				ok=false;
				break;
			}*/
    		if(ok){
    			//dbgm(i,j);
    			ans++;
    		} 
    	}
    }
    cout<<ans<<"\n";
    
    
    
    
    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}








