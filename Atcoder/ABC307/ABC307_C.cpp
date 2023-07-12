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
bool verificarSubmatriz(const std::vector<std::vector<char>>& GRANDE
                        , const std::vector<std::vector<char>>& B) {
    int m = GRANDE.size();
    int n = GRANDE[0].size();
    int p = B.size();
    int q = B[0].size();

    for (int i = 0; i <= m - p; i++) {
        for (int j = 0; j <= n - q; j++) {
            bool found = true;
            for (int x = 0; x < p; x++) {
                for (int y = 0; y < q; y++) {
                    if (GRANDE[i + x][j + y] != B[x][y]) {
                        found = false;
                        break;
                    }
                }
                if (!found)
                    break;
            }
            if (found)
                return true;
        }
    }

    return false;
}
void solve(){
    ll ha,wa,hb,wb,hx,wx;
    cin>>ha>>wa;
    vector<vector<char>> A(ha,vector<char>(wa));
    FOR(i,0,ha){
        FOR(j,0,wa){
            cin>>A[i][j];
        }
    }
    cin>>hb>>wb;
    vector<vector<char>> B(hb,vector<char>(wb));
    FOR(i,0,hb){
        FOR(j,0,wb){
            cin>>B[i][j];
        }
    }
    cin>>hx>>wx;
    vector<vector<char>> X(hx,vector<char>(wx));
    FOR(i,0,hx){
        FOR(j,0,wx){
            cin>>X[i][j];
        }
    }
    ll arribax=LONG_LONG_MAX,arribay=LONG_LONG_MAX,coordx=LONG_LONG_MIN,coordy=LONG_LONG_MIN;
    FOR(i,0,hx){
        FOR(j,0,wx){
            if(X[i][j]=='#'){
                coordx=max(coordx,i);
                coordy=max(coordy,j);
                arribax=min(arribax,i);
                arribay=min(arribay,j);
            }
        }
    }
    //dbgm(arribax,arribay,coordx,coordy);
    vector<vector<char>> newX;
    FOR1(i,arribax,coordx){
        vector<char> auxi;
        FOR1(j,arribay,coordy){
            auxi.pb(X[i][j]);
        }
        newX.pb(auxi);
    }
    hx=newX.size();
    wx=0;
    if(newX.size()!=0){
        wx=newX[0].size();
    }
    /*cout<<"NEW X\n";
    FOR(i,0,hx){
        FOR(j,0,wx){
            cout<<newX[i][j];
        }
        cout<<"\n";
    }*/
    FOR(i,0,hx){
        FOR(j,0,wx){
            FOR(itn,0,hx){
                FOR(itn2,0,wx){
                    vector<vector<char>> aux(10,vector<char>(10,'.'));
                    FOR(k,0,ha){
                        if(k+itn > 9 ) continue;
                        FOR(l,0,wa){
                            if(l+itn2>9) continue;
                            if(A[k][l]=='#')
                                aux[k+itn][l+itn2]=A[k][l];
                        }
                    }
                    FOR(k,0,hb){
                        if(k+i > 9) continue;
                        FOR(l,0,wb){
                            if(l+j>9) continue;
                            if(B[k][l]=='#')
                                aux[k+i][l+j]=B[k][l];
                        }
                    }
                    if(verificarSubmatriz(aux,newX)){
                        cout<<"Yes\n";
                        return;
                    }
                }
            }


        }
    }
    cout<<"No\n";
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








