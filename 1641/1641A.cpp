#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
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
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;
const int N=1000+3;

void solve(){
    ll n,x;
    cin>>n>>x;
    map<ll,ll> m;
    FOR(i,0,n){
        ll aux;
        cin>>aux;
        m[aux]++;
    }
    ll ans=0;
    for(auto &e : m){
            //cout<<e.first<<" "<<e.second<<"\n";
            while(e.second>0){
                if(m.count (e.first*x) && m[e.first*x]>0){
                    m[e.first*x]--;
                    e.second--;
                }
                else if(e.first%x==0 && m.count(e.first/x) && m[e.first/x]>0){
                    m[e.first/x]--;
                    e.second--;
                }
                else{
                    if(e.second>0){
                        ans++;
                        e.second--;
                    }
                }
            }
    }
    for(auto e : m){
        ans+=e.second;
    }
    cout<<ans<<"\n";

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








