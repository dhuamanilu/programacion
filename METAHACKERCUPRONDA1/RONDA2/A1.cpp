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
const int N=1000+3;
ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};
bool isValid(ll r,ll c,ll x,ll y){
    return x>=1 && x<=r && y>=1 && y<=c;
}
bool estaEncerrado(ll i,ll j,vector<vector<char>> &a
                   ,vector<vector<bool>> &vis,ll r,ll c){
    //dbgm("esEN",i,j);
    bool ok=true;
    vis[i][j]=true;

    FOR(it,0,4){
        ll newX=i+dx[it];
        ll newY=j+dy[it];
        dbgm(i,j,newX,newY);
        if(isValid(r,c,newX,newY)){
            if(a[newX][newY]=='.'){
                ok=false;
                break;
            }
            //if(vis[i][j]) continue;

            if(a[newX][newY]=='B'){
                continue;
            }
            else if(a[newX][newY]=='W'){
                if(estaEncerrado(newX,newY,a,vis,r,c)){
                    continue;
                }
            }
        }
    }
    return ok;
}
bool verifica(vector<vector<char>> &a,vector<vector<bool>> &vis
              ,ll r,ll c){
    bool ok=false;
    FOR1(i,1,r){
        FOR1(j,1,c){
            if(vis[i][j]) continue;
            if(a[i][j]=='W'){
                if(estaEncerrado(i,j,a,vis,r,c)){
                    //dbgm("asdasasdasdasasdas",i,j);
                    ok=true;
                    break;
                }

            }
        }
        if(ok){
            break;
        }
    }
    return ok;
}
void solve(ll ind){
    ll r,c;
    cin>>r>>c;
    vector<vector<char>> a(r+2,vector<char>(c+2,'B'));
    FOR1(i,1,r){
        FOR1(j,1,c){
            cin>>a[i][j];
        }
    }
    //dbg(a);
    bool okGeneral=false;
    FOR1(i,1,r){
        FOR1(j,1,c){
            //pondre una ficha negra en a i j
            if(a[i][j]!='.') continue;
            a[i][j]='B';
            vector<vector<bool>> vis(r+2,vector<bool>(c+2,false));

            bool ok=verifica(a,vis,r,c);
            if(ok) dbgm("encontre en ",i,j);
            a[i][j]='.';
            if(ok){
                okGeneral=true;
                break;
            }
        }
        if(okGeneral){
            break;
        }
    }
    if(okGeneral){
        cout<<"Case #"<<ind<<": "<<"YES"<<"\n";
    }
    else{
        cout<<"Case #"<<ind<<": "<<"NO"<<"\n";
    }



}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t=1;
    cin>>t;
    FOR(i,0,t){
        solve(i+1);
    }
    return 0;
}








