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
    ll n;
    cin>>n;
    ll a[n];
    ll cont=0;
    ll ind=0;
    FOR(i,0,n){
        cin>>a[i];
        if(a[i]==-1){
            cont++;
            ind=i;
        }
    }
    if((n-2*cont)%2==1 || n%2==1){
        cout<<"-1\n";
    }
    else{
        vector <pair<ll,ll > > ans;
        for(ll i=0;i<n;i+=2){
            if(a[i]==a[i+1]){
                ans.push_back(mp(i+1,i+2));
            }
            else{
                ans.push_back(mp(i+1,i+1));
                ans.push_back(mp(i+2,i+2));
            }
        }
        cout<<ans.size()<<"\n";
        for(auto e : ans){
            cout<<e.first<<" "<<e.second<<"\n";
        }
    }
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








