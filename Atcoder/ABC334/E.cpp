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
const int MAXN = 200005;
const int N=1000+5;
vector<vector<bool>> vis(N,vector<bool>(N,false));
vll dx={1,-1,0,0};
vll dy={0,0,1,-1};
ll h,w;
vector<vll> id(N,vector<ll>(N));
vector<vll> a(N,vll(N));
bool isValid(ll x,ll y){
	return x>=0 && x<h && y>=0 && y<w;
}
void dfs(ll x,ll y,ll identi){
	vis[x][y]=true;
	id[x][y]=identi;
	FOR(i,0,4){
		ll newX=x+dx[i],newY=y+dy[i];
		if(isValid(newX,newY)){
			if(!vis[newX][newY]
			&& a[newX][newY]){
				dfs(newX,newY,identi);
			}
		}
	}
}
long long calculate(long long p, 
                    long long q) 
{ 
    long long mod = 998244353, expo; 
    expo = mod - 2; 
 
    // Loop to find the value 
    // until the expo is not zero 
    while (expo) { 
 
        // Multiply p with q 
        // if expo is odd 
        if (expo & 1) { 
            p = (p * q) % mod; 
        } 
        q = (q * q) % mod; 
 
        // Reduce the value of 
        // expo by 2 
        expo >>= 1; 
    } 
    return p; 
}
void solve(){
	cin>>h>>w;
	FOR(i,0,h){
		string s;
		cin>>s;
		FOR(j,0,w){
			a[i][j]=(s[j]=='#');
		}
	}
	//dbg(a);
	ll act=1;
	FOR(i,0,h){
		FOR(j,0,w){
			if(!vis[i][j] && a[i][j]){
				dfs(i,j,act);
				act++;
			}
		}
	}
	vll cont(4,0);
	ll ans=0;
	/*FOR(i,0,h){
		FOR(j,0,w){
			cout<<id[i][j]<<" ";
		}
		cout<<"\n";
	}*/
	ll den=0;
	FOR(i,0,h){
		FOR(j,0,w){
			if(a[i][j]) continue;
			den++;
			set<ll> cant;
			FOR(k,0,4){
				ll newX=i+dx[k]
				,newY=j+dy[k];
				if(isValid(newX,newY)){
					//dbgm(newX,newY,id[newX][newY]);
					if(a[newX][newY]){		
						cant.insert(id[newX][newY]);
					} 
				}
			}
			//dbgm(i,j,cant.size());
			ans+=act-(ll)cant.size();
		}
		
	}
	
	//cout<<ans<<" "<<den<<"\n";
    cout<<calculate(ans,den)<<"\n";
    
    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--){
		solve();
    }
    return 0;
}








