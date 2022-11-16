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
    ll a[n];
    FOR(i,0,n){
        cin>>a[i];
    }
    ll j=0;
    vector <ll> ind;
    while(j<n){
        ll i=j,sum=0;
        while(i<n && sum%2==0){
            sum+=a[i++];
        }
        if(sum%2==1){
            ind.push_back(i);
        }
        j=i;
    }
    if(ind.size()<k){
        cout<<"NO\n";
        return;
    }
    else{
        if(ind.size()%2!=k%2){
            cout<<"NO\n";
            return;
        }
        else{
            cout<<"YES\n";
            FOR(i,0,k-1){
                cout<<ind[i]<<" ";
            }
            cout<<n<<"\n";
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








