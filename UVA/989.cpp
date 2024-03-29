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
const int N=12;
ll a[N][N];
ll n;
bool okG=false;
vector<vll> enFila(N,vll(N,0));
vector<vll> enColumna(N,vll(N,0));
map<pair<ll,ll>,vector<ll>> enCuadrado;
pair<ll,ll> get_cuadrado(ll row,ll col){
	for(ll i=1;i<=n*n;i+=n){
		for(ll j=1;j<=n*n;j+=n){
			ll xx=i+n-1,yy=j+n-1;
			if(row>=i && row<=xx && col>=j && col<=yy)
				return mp(i,j);
		}
	}
}
void go(ll row,ll col){
	if(okG) return;
	//dbgm("toca",row,col);
	if(row==n*n+1 && col==1){
		bool ok=true;
		FOR1(i,1,n*n){
			FOR1(j,1,n*n){
				if(enFila[i][j]!=1){
					ok=false;
					break;
				}
				if(enColumna[i][j]!=1){
					ok=false;
					break;
				}
			}
		}
		for(ll i=1;i<=n*n;i+=n){
			for(ll j=1;j<=n*n;j+=n){
				vll numeros(n*n+1,0);
				FOR(k,0,n){
					FOR(it,0,n){
						ll newX=i+k,newY=j+it;
						numeros[a[newX][newY]]++;
					}
				}
				FOR1(iter,1,n*n){
					if(numeros[iter]!=1){
						ok=false;
						break;
					}
				}

			}
		}
		if(ok){
			FOR1(i,1,n*n){
		    	FOR1(j,1,n*n){
		    		
		    		cout<<a[i][j];
		    		if(j!=(n*n)){
		    			cout<<" ";
		    		}
		    	}
		    	cout<<"\n";
		    }
		    okG=true;
		    return;
		}
	}
	if(a[row][col]==0){
		pair<ll,ll> cua=get_cuadrado(row,col);
		/*if(row==2 && col==1){
			dbgm("21",enCuadrado[cua]);
		}*/

		FOR1(i,1,n*n){
			auto it=find(all(enCuadrado[cua]),i);
			//dbgm(row,col,cua);
			if(!enFila[row][i] &&
			!enColumna[col][i]
			&& it==
			enCuadrado[cua].end()){
				//dbgm("prob",row,col,i);
				a[row][col]=i;
				enFila[row][i]++;
				enColumna[col][i]++;
				enCuadrado[cua].pb(i);
				if(col+1<=n*n){
					go(row,col+1);
				}
				else{
					go(row+1,1);
				}
				enFila[row][i]--;
				enColumna[col][i]--;
				auto porsiacaso=find(all(enCuadrado[cua]),i);
				enCuadrado[cua].erase(porsiacaso);
				//dbgm("des",row,col,i);
				a[row][col]=0;
			}
		}
	}
	else{
		if(col+1<=n*n){
			go(row,col+1);
		}
		else{
			go(row+1,1);
		}
	}
}
void solve(){
	ll foo=0;
    while(cin >> n){
    	//dbg(n);
    	okG=false;
    	if(foo)cout<<"\n";
    	foo=1;
    	FOR1(i,1,n*n){
	    	FOR1(j,1,n*n){
	    		cin>>a[i][j];
	    	}
	    }
	    enCuadrado.clear();
	    //dbg(a);
	    FOR1(i,1,n*n){
			FOR1(j,1,n*n){
				enFila[i][j]=0;
				enColumna[i][j]=0;
			}
		}

	    FOR1(i,1,n*n){
			FOR1(j,1,n*n){
				enFila[i][a[i][j]]++;
				enColumna[i][a[j][i]]++;
			}
		}
		for(ll i=1;i<=n*n;i+=n){
			for(ll j=1;j<=n*n;j+=n){
				FOR(k,0,n){
					FOR(it,0,n){

						ll newX=i+k,newY=j+it;
						if(a[newX][newY]==0) continue;
						auto cua=mp(i,j);
						enCuadrado[cua].pb(a[newX][newY]);
					}
				}
			}
		}
		//dbg(enCuadrado);
	    go(1,1);
	    if(!okG){
	    	cout<<"NO SOLUTION\n";
	    }
	    char x=getchar();
	    //dbg(x);
    }

}
int main(){
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);*/
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}








