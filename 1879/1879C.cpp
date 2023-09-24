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
const int MOD = 998244353;
const char nl = '\n';
const int MX = 200005;
const int N=1000+3;
ll fact[MX];
void precalc(){
    fact[1]=1;
    FOR(i,2,MX){
        fact[i]=i*fact[i-1];
        fact[i]%=MOD;
    }
}
void solve(){
    string s;
    cin>>s;
    ll n=s.size();
    vll pos1;
    vll pos0;
    //pos1.pb(-1);
    //pos0.pb(-1);
    FOR(i,0,n){
        if(s[i]=='1'){
            pos1.pb(i);
        }
        else{
            pos0.pb(i);
        }
    }
    //pos1.pb(n);
    //pos0.pb(n);
    //que empieze en 1
    ll mov=0;
    ll ans1=1;
    if((ll)pos1.size()>=1 && pos1[0]!=0){
        mov+=pos1[0];
        ans1*=fact[pos1[0]];
        ans1%=MOD;
    }
    FOR(i,0,(ll)pos1.size()-1){
        if(pos1[i]+1!=pos1[i+1]){
            mov+=(pos1[i+1]-pos1[i]-2);
            ans1*=fact[pos1[i+1]-pos1[i]-1];
            ans1%=MOD;
        }
        else{
            ll esp=0;
            while(i+1<pos1.size() && pos1[i]+1==pos1[i+1]){
                esp++;
                mov++;
                i++;
            }
            ans1*=fact[esp+1];
            ans1%=MOD;
        }
    }

    //que empieze en 0
    ll movi=0;
    ll ans2=1;
    if((ll) pos0.size()>=1 && pos0[0]!=0){
        movi+=pos0[0];
        ans2*=fact[pos0[0]];
        ans2%=MOD;
    }
    FOR(i,0,(ll)pos0.size()-1){
        if(pos0[i]+1!=pos0[i+1]){
            movi+=(pos0[i+1]-pos0[i]-2);
            ans2*=fact[pos0[i+1]-pos0[i]-1];
            ans2%=MOD;
        }
        else{
            ll esp=0;
            while(i+1<pos0.size() && pos0[i]+1==pos0[i+1]){
                esp++;
                movi++;
                i++;
            }
            ans2*=fact[esp+1];
            ans2%=MOD;
        }
    }


    //dbgm(mov,movi);
    if((ll)pos1.size()==0){
        mov=n;
        ans1=fact[n];
    }
    if((ll)pos0.size()==0){
        movi=n;
        ans2=fact[n];
    }
    if(mov==movi){
        cout<<mov<<" "<<(ans1+ans2)%MOD<<"\n";
    }
    if(mov<movi){
        cout<<mov<<" "<<ans1<<"\n";
    }
    else{
        cout<<movi<<" "<<ans2<<"\n";
    }

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    precalc();
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}








