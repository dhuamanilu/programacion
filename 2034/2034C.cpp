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
vl dx={-1,1,0,0};
vl dy={0,0,1,-1};
//U D R L
vl quiero={1,0,2,3};                                                                                                                                                                                                                                                                                         
ll solve(vector<vl> &a) {
	ll n=a.size(),m=a[0].size();
	
	ll cont=0;
	auto isValid=[&](ll x,ll y){
		return x>=0 && x<n && y>=0 && y<m;
	};
	vector<vl> bad(n,vl(m,0));
	//1 siginifica que si es iun indice malo
	FOR(i,0,n){
		FOR(j,0,m){
			if(a[i][j]==4){
				FOR(k,0,4){
					ll newX=i+dx[k],newY=j+dy[k];
					if(isValid(newX,newY) && a[newX][newY]==4){
						bad[i][j]=1;
						cont++;
						break;
					}
				}
			}
			
		}
	}
	FOR(i,0,n){
		FOR(j,0,m){
			if(a[i][j]==4){
				bool ok=true;
				FOR(k,0,4){
					ll newX=i+dx[k],newY=j+dy[k];
					if(isValid(newX,newY) && a[newX][newY]==4){
						ok=false;
						break;
					}
				}
				if(ok){
					bool found=false;
					FOR(k,0,4){
						
						ll newX=i+dx[k],newY=j+dy[k];
						if(i==1 && j==1)
						dbg(k,newX,newY,quiero[k]);
						if(i==1 && j==1 && isValid(newX,newY)) dbg(a[newX][newY]);
						if(isValid(newX,newY) && a[newX][newY]==quiero[k]){
							bad[i][j]=1;
							bad[newX][newY]=1;	
							if(!found)
								cont+=2;
							else cont++;
							found=true;
						}
					}
				}
			}
			
		}
	}
	map<pl,ll> path;
	vector<vl> vis(n,vl(m,0));
	auto dfs=[&](auto &&dfs, ll x,ll y)->void{
		path[mp(x,y)]++;
		vis[x][y]=1;
			ll k=-1;
			if(a[x][y]=='U') k=0;
			else if(a[x][y]=='D') k=1;
			else if(a[x][y]=='R') k=2;
			else if(a[x][y]=='L') k=3;
			else{
				if(bad[x][y]==1){
					cont+=(ll)path.size();
					each(e,path){
						bad[e.f.f][e.f.s]=1;
					}
					path.clear();
					return;
				}
				else{
					return;
				}
			}
			ll newX=x+dx[k],newY=y+dy[k];
			if(isValid(newX,newY)){
				if( !vis[newX][newY]){
					if(bad[newX][newY]==1){
						cont+=(ll)path.size();
						each(e,path){
							bad[e.f.f][e.f.s]=1;
						}
						path.clear();
						return;
					}
					else{
						dfs(dfs,newX,newY);
					}
				}
				
			}
			else return;
		
	};
	FOR(i,0,n){
		FOR(j,0,m){
			if(a[i][j]!=4 && !bad[i][j]){
				if(!vis[i][j])
					dfs(dfs,i,j);
			}
		}
	}
	dbg("conta tnes",cont);
	FOR(i,0,n){
		FOR(j,0,m){
			if(a[i][j]==4){
				bool ok=true;
				FOR(k,0,4){
					ll newX=i+dx[k],newY=j+dy[k];
					if(isValid(newX,newY) && a[newX][newY]==4){
						ok=false;
						break;
					}
				}
				if(ok){
					//? con todo alredodr no preguntita
					dbg(i,j,bad[i][j]);
					if(!bad[i][j]){
						FOR(k,0,4){
							ll newX=i+dx[k],newY=j+dy[k];
							dbg("ultima oportunidad",newX,newY);
							if(isValid(newX,newY)) dbg(bad[newX][newY]);
							if(isValid(newX,newY) && bad[newX][newY]==1){
								bad[i][j]=1;
								cont++;
								break;
							}
						}
					}

				}
			}
			
		}
	}
	return cont;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;

    for(int idx = 0; idx < t; idx++) {
        RAYA;
        RAYA;
		ll n,m;
		cin>>n>>m;
		vector<vl> a(n,vl(m,0));
		each(e,a){
			str s;
			cin>>s;
			FOR(j,0,m){
				if(s[j]=='U')
					e[j]=0;
				else if(s[j]=='D')
					e[j]=1;
				else if(s[j]=='R')
					e[j]=2;	
				else if(s[j]=='L')
					e[j]=3;	
				else e[j]=4;
			}
		}
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








