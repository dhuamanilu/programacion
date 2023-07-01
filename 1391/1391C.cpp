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
/*bool cicle(ll v,vector<bool> &vis,ll par,vector<vll> &G){
    vis[v]=true;
    for(auto e : G[v]){
        if(!vis[e]){
            if(cicle(e,vis,v,G)) return true;
        }
        else if(e!=par) return true;
    }
    return false;
}*/
void solve(){
    ll n;
    cin>>n;
    ll ans=1;
    FOR1(i,1,n){
        ans*=i;
        ans%=MOD;
    }
    ll pow=1;
    FOR(i,0,n-1){
        pow*=2;
        pow%=MOD;
    }
    ans-=pow;
    ans+=MOD;
    ans%=MOD;
    cout<<ans<<"\n";
    /*vll a(n);
    FOR(i,0,n){
        a[i]=i+1;
    }
    ll ans=0;
    do{
        vector<vll> G(n+5);
        FOR(i,0,n){
            ll ind=i-1;
            while(ind>=0){
                if(a[ind]>a[i]){
                    break;
                }
                ind--;
            }
            if(ind>=0){
                G[i].pb(ind);
                G[ind].pb(i);
            }

        }
        FOR(i,0,n){
            ll ind=i+1;
            while(ind<n){
                if(a[ind]>a[i]){
                    break;
                }
                ind++;
            }
            if(ind<n){
                G[i].pb(ind);
                G[ind].pb(i);
            }

        }

        vector<bool> vis(n+5,false);
        FOR1(i,1,n){
            if(!vis[i]){
                if(cicle(i,vis,-1,G)){
                    ans++;
                    ans%=MOD;
                    break;
                }
            }
        }

    }while(next_permutation(all(a)));
    cout<<ans<<"\n";*/
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








