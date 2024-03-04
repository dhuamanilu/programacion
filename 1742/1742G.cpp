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
#define lb lower_boun
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


vll solve2(vll a){
	ll n=a.size();
	vll b(n);
	iota(all(b),0ll);
	//dbgm(b);
	vll res;
	vll mejor(n,0);
	do{
		vll act(n,0);
		act[0]=a[b[0]];
		FOR(i,1,n){
			act[i]=act[i-1]|a[b[i]];
		}
		bool ok=false;
		FOR(i,0,n){
			if(act[i]>mejor[i]){
				ok=true;
				break;
			}
		}
		if(ok){
			mejor=act;
			res=b;
		}
	}while(next_permutation(all(b)));
	return res;
}
vll solve(vll &a){
	ll n=a.size();
	/*retornaremos los indices finales de mi 
	arreglo que maximiza el pref or*/
    vector<vll> tiene(32);
    FOR(it,0,n){
        for(ll i=31;i>=0;i--){
    		ll act=1ll<<i;
    		ll x=a[it];
    		if((act&x)){
    			tiene[i].pb(it);
    		}
    		
    	}
    }
    //dbg(tiene);
    FOR(it,0,32){
    	//dbgm("befire",tiene[i]);
    	ll start=it;
    	sort(all(tiene[it]),
    	[&](ll pri,ll seg){
    	for(ll i=start;i>=0;i--){
    		ll x=a[pri],y=a[seg];
    		ll act=1ll<<i;
    		if((act&x) && !(act&y)){
    			return true;
    		}
    		else if(!(act&x) && (act&y)){
    			return false;
    		}
    	}
    	return false;
    	});
    	//dbgm("afeter:",tiene[i]);
    }
    ll pref=0;
    vll inds;
    vll vis(n,0);
    for(ll i=31;i>=0;i--){
    	ll act=1ll<<i;
    	
    	if(!(pref&act) && tiene[i].size()){
    		ll j=0;
    		while(vis[tiene[i][j]] && j<tiene[i].size()){
    			j++;
    		}
    		vis[tiene[i][j]]=true;
    		inds.pb(tiene[i][j]);
    		pref|=a[tiene[i][j]];
    	}
    }
    FOR(i,0,n){
    	if(!vis[i]){
    		vis[i]=true;
    		inds.pb(i);
    	}
    }
    return inds;
    /*FOR(i,0,n){
    	cout<<a[inds[i]]<<" ";
    }
    cout<<"\n";*/
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(time(0)); 

    int t=1;
    //cin>>t;
    while(true){
    	/*ll n;
		cin>>n;
		vll a(n);
		FOR(i,0,n){
			cin>>a[i];
		}
    	auto ans=solve(a);
    	for(auto & e : ans){
    		cout<<a[e]<<" ";
    	}
    	cout<<"\n";*/
        ll tam=rand()%9+1;
        vll a(tam);
		FOR(i,0,tam){
			a[i]=rand()%100+1;
		}
		//dbg(a);
    	auto ans1=solve(a);
    	auto ans2=solve2(a);
    	
    	
    	//dbgm(ans1,ans2);
    	ll pref1=a[ans1[0]];
    	ll pref2=a[ans2[0]];
    	FOR(i,1,tam){
    		if(pref2>pref1){
    			dbgm("xd",ans2,ans1,a,pref2,pref1);
    			assert(false);
    		}
    		pref1|=a[ans1[i]];
    		pref2|=a[ans2[i]];
    	}
    	if(pref2>pref1){
			dbgm("xd",ans2,ans1,a,pref2,pref1);
			assert(false);
		}
    }
    return 0;
}








