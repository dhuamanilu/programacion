#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
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
void ctmr(){
    vll primos;
    FOR1(j,1,1e5){
        bool ok=true;
        for(ll i=2;i*i<=j;i++){
            if(j%i==0){
                ok=false;
                break;
            }
        }
        if(ok) primos.pb(j);
    }
    cout<<"aasdd "<<primos.back()<<"\n";


}
void solve(){
    ll n;
    cin>>n;
    ll a[n];
    priority_queue<pair<ll,ll>> pq;
    FOR(i,0,n){
        cin>>a[i];
        pq.push(mp(a[i],i+1));
    }
    vector <pll> v;
    while(pq.size()>=2){
        auto x=pq.top();
        pq.pop();
        auto y=pq.top();
        pq.pop();
        if(x.f>0 && y.f>0){
            x.f--;
            y.f--;
            v.push_back(mp(x.se,y.se));
        }
        if(x.f>0) pq.push(mp(x.f,x.se));
        if(y.f>0) pq.push(mp(y.f,y.se));
    }
    cout<<v.size()<<"\n";
    for(auto e : v){
        cout<<e.f<<" "<<e.se<<"\n";
    }


}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    /*int t=1;
    cin>>t;
    while(t--){
        solve();
    }*/
    ctmr();
    return 0;
}








