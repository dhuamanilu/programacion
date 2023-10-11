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
long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}
vpll get_factors(ll x){
    vpll ans;
    ll x2=x;
    for(ll i=2;i*i<=x;i++){
        if(x2%i==0){
            ll cont=0;
            while(x2%i==0){
                cont++;
                x2/=i;
            }
            if(cont>0){
                ans.pb({i,cont});
            }
        }
    }
    if(x2>1){
        ans.pb({x2,1});
    }
    return ans;
}
void solve(ll ind){
    ll n;
    cin>>n;
    auto x=get_factors(n);
    bool ok=true;
    ll sum=0;
    vll ans;
    for(auto & e : x){
        ll primo=e.f;
        ll expo=e.se;
        if(primo>41){
            ok=false;
            break;
        }
        FOR(i,0,expo){
            ans.pb(primo);
            sum+=primo;
        }
    }
    //dbg(ans);
    if(!ok){
        cout<<"Case #"<<ind<<": "<<"-1\n";
    }

    else{
        if(sum<=41){
            FOR(i,0,41-sum){
                ans.pb(1);
            }
            cout<<"Case #"<<ind<<": "<<ans.size()<<" ";
            FOR(i,0,(ll)ans.size()){
                if(i<(ll)ans.size()-1){
                    cout<<ans[i]<<" ";
                }
                else cout<<ans[i];
            }
            cout<<"\n";
        }
        else{
            cout<<"Case #"<<ind<<": "<<"-1\n";
        }
    }








}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen("sum_41_chapter_1_input.txt", "r")) {
		freopen("sum_41_chapter_1_input.txt", "r", stdin);
		freopen("out2true.txt", "w", stdout);
    }
    int t=1;
    cin>>t;
    FOR(i,0,t){
        solve(i+1);
    }
    return 0;
}








