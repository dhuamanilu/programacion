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
#define n_l '\n'
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; cout << to_string(__VA_ARGS__) << endl
template <typename T, size_t N> int SIZE(const T (&t)[N]){ return N; } template<typename T> int SIZE(const T &t){ return t.size(); } string to_string(const string s, int x1=0, int x2=1e9){ return '"' + ((x1 < s.size()) ? s.substr(x1, x2-x1+1) : "") + '"'; } string to_string(const char* s) { return to_string((string) s); } string to_string(const bool b) { return (b ? "true" : "false"); } string to_string(const char c){ return string({c}); } template<size_t N> string to_string(const bitset<N> &b, int x1=0, int x2=1e9){ string t = ""; for(int __iii__ = min(x1,SIZE(b)),  __jjj__ = min(x2, SIZE(b)-1); __iii__ <= __jjj__; ++__iii__){ t += b[__iii__] + '0'; } return '"' + t + '"'; } template <typename A, typename... C> string to_string(const A (&v), int x1=0, int x2=1e9, C... coords); int l_v_l_v_l = 0, t_a_b_s = 0; template <typename A, typename B> string to_string(const pair<A, B> &p) { l_v_l_v_l++; string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; l_v_l_v_l--; return res; } template <typename A, typename... C> string to_string(const A (&v), int x1, int x2, C... coords) { int rnk = rank<A>::value; string tab(t_a_b_s, ' '); string res = ""; bool first = true; if(l_v_l_v_l == 0) res += n_l; res += tab + "["; x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v)); auto l = begin(v); advance(l, x1); auto r = l; advance(r, (x2-x1) + (x2 < SIZE(v))); for (auto e = l; e != r; e = next(e)) { if (!first) { res += ", "; } first = false; l_v_l_v_l++; if(e != l){ if(rnk > 1) { res += n_l; t_a_b_s = l_v_l_v_l; }; } else{ t_a_b_s = 0; } res += to_string(*e, coords...); l_v_l_v_l--; } res += "]"; if(l_v_l_v_l == 0) res += n_l; return res; } void dbgm(){;} template<typename Heads, typename... Tails> void dbgm(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgm(T...); }
#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgm(__VA_ARGS__); cout << endl
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;
const int N=105;
bool vis[N][N];
char a[N][N];
string sn="snuke";
vector<pair<ll,ll>> ans;
ll h,w;
bool isValid(ll i,ll j){
    return i>=0 && i<h && j>=0 && j<w;
}

void solve(){

    cin>>h>>w;
    FOR(i,0,h){
        string s;
        cin>>s;
        FOR(j,0,w){
            a[i][j]=s[j];
        }
    }
    map<ll,pair<ll,ll>> m;
    ll dx[]={1,-1,0,0,1,1,-1,-1};
    ll dy[]={0,0,1,-1,1,-1,-1,1};
    FOR(i,0,8){
        m[i]={dx[i],dy[i]};
    }
    FOR(i,0,h){
        FOR(j,0,w){
            if(a[i][j]!='s') continue;
            FOR(k,0,8){
                string aux="s";
                ans.pb({i,j});
                ll ni=i,nj=j,cont=1;
                while(ni<h && nj<w && cont<5){
                    ans.pb({ni+m[k].f,nj+m[k].se});
                    aux+=a[ni+m[k].f][nj+m[k].se];
                    ni+=m[k].f;
                    nj+=m[k].se;
                    cont++;
                }
                if(aux!=sn){
                    ans.clear();
                }
                else{
                    for(auto & e :ans){
                        cout<<e.f+1<<" "<<e.se+1<<"\n";
                    }
                    return;
                }

            }
        }
    }
    /*FOR(i,0,h){
        FOR(j,0,w){
            ll cont=0;

            FOR(k,0,9){
                ll nx=i+dx[i],ny=j+dy[j];
                if(isValid(nx,ny)){
                    if(a[nx][ny]==sn[cont]){
                        ans.pb({nx,ny});
                        cont++;
                        if(j==w-1)
                            i=nx-1;
                        else
                            i=nx;
                        j=ny-1;
                        break;
                    }
                }

            }
        }
    }
    FOR(i,0,N){
        FOR(j,0,N){
            vis[i][j]=false;
        }
    }
    FOR(i,0,h){
        FOR(j,0,w){
            if(!vis[i][j]) dfs(i,j,0);
        }
    }
    for(auto & e: ans){
        cout<<e.f<<" "<<e.se<<"\n";
    }*/
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








