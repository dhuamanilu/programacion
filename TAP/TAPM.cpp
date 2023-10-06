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
    ll n,t;
    cin>>n>>t;
    map<double,double> prio,noPrio;
    FOR(i,0,n){
        char a;
        cin>>a;
        ll xi;
        cin>>xi;
        if(a=='P'){
            prio[xi]++;
        }
        else{
            noPrio[xi]++;
        }
    }

    double ans=0;
    while(prio.size() || noPrio.size()){
        //dbgm(prio,noPrio);
        double veloPrioActual=0;
        double veloNoPrioActual=0;
        double cantidad1=0,cantidad2=0;
        for(auto & e : prio){
            cantidad1+=e.se;
        }
        for(auto & e : noPrio){
            cantidad2+=e.se;
        }
        double mult1=0.75,mult2=0.25;
        if((ll)prio.size()==0){
            mult1=0;
            mult2=1;
        }
        if((ll)noPrio.size()==0){
            mult1=1;
            mult2=0;
        }
        if(prio.size()>0)
            veloPrioActual=mult1*t/cantidad1;
        if(noPrio.size()>0)
            veloNoPrioActual=mult2*t/cantidad2;
        double temp1=1e15;
        double temp2=1e15;
        if(veloPrioActual>0)
            temp1=1.0*prio.begin()->first/veloPrioActual;
        if(veloNoPrioActual>0)
            temp2=1.0*noPrio.begin()->first/veloNoPrioActual;
        //dbgm(veloPrioActual,veloNoPrioActual,temp1,temp2);
        if(temp1<temp2){
            ans+=temp1;
            prio.erase(prio.begin()->first);
            vector<pair<double,double>> aux1;
            for(auto & e : prio){
                aux1.pb(e);
            }
            for(auto & e : aux1){
                e.f-=temp1*veloPrioActual;
            }
            prio.clear();
            for(auto & e : aux1){
                prio[e.f]=e.se;
            }


            vector<pair<double,double>> aux2;
            for(auto & e : noPrio){
                aux2.pb(e);
            }
            for(auto & e : aux2){
                e.f-=temp1*veloNoPrioActual;
            }
            noPrio.clear();
            for(auto & e : aux2){
                noPrio[e.f]=e.se;
            }
        }
        else{
            ans+=temp2;
            noPrio.erase(noPrio.begin()->first);
            vector<pair<double,double>> aux1;
            for(auto & e : prio){
                aux1.pb(e);
            }
            for(auto & e : aux1){
                e.f-=temp2*veloPrioActual;
            }
            prio.clear();
            for(auto & e : aux1){
                prio[e.f]=e.se;
            }


            vector<pair<double,double>> aux2;
            for(auto & e : noPrio){
                aux2.pb(e);
            }
            for(auto & e : aux2){
                e.f-=temp2*veloNoPrioActual;
            }
            noPrio.clear();
            for(auto & e : aux2){
                noPrio[e.f]=e.se;
            }
        }
        //dbg(ans);
    }
    cout<<fixed<<setprecision(6)<<ans<<"\n";
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








