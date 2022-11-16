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
    ll n,k;
    cin>>n>>k;
    map <ll,ll> m;
    FOR(i,0,n){
        ll a;
        cin>>a;
        m[a%k]++;
    }
    ll maxi=0,cont=0,resta=0;
    for(auto e : m){
        cont++;
        resta=k-e.f;
        if(e.f==0) continue;
        maxi=max(maxi,e.se);
    }
    if(m.size()==1 && m.count(0)){
        cout<<"0\n";
        return;
    }
    if(cont==1){
        maxi=k*(maxi-1)+1+resta;
        cout<<maxi<<"\n";
        return;
    }
    cout<<k*maxi<<"\n";

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








