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

void solve(){
    ll n,k;
    cin>>n>>k;
    ll a[n];
    vector<vector<ll>> pos(k+1,vector<ll>());
    FOR(i,0,n){
        cin>>a[i];
        pos[a[i]].pb(i);
    }
    //dbg(pos);
    vector<vector<ll>> valores(k+2,vector<ll>(2,0));
    //Minimo
    valores[k][0]=0;
    //Maximo
    valores[k][1]=0;
    //ACAAAAAA
    for(ll i=k;i>=1;i--){
        if(pos[i].size()>0){
            //cout<<"asdasds : "<<pos[i].front()<<"\n";
            valores[i][0]=min(valores[i+1][0],pos[i].back());
            valores[i][1]=max(valores[i+1][1],pos[i].back());
        }
        else{
            valores[i][0]=valores[i+1][0];
            valores[i][1]=valores[i+1][1];
        }
    }
    if(pos[k].size()>0){
        valores[k+1][0]=pos[k].front();
        valores[k+1][1]=pos[k].back();
    }
    else{
        valores[k+1][0]=0;
        valores[k+1][1]=0;
    }
    //dbg(valores);
    //No useaos valores[0][j]
    //Para hallar el diff es el maximo entre
    FOR1(i,1,k){
        ll ans1=0;
        //cout<<"2 ";
        if(pos[i].size()>0){
            ans1=abs(pos[i].front()-valores[i+1][1])+abs(pos[i].back()-valores[i+1][0]);
            cout<<2*(ans1+1)<<" ";
        }
        else{
            cout<<"0 ";
        }
    }
    cout<<"\n";
    //dbg(valores);

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








