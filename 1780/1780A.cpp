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
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;
const int N=1000+3;

void solve(){
    ll n;
    cin>>n;
    ll a[n];
    vll b(2,0);
    FOR(i,0,n){
        cin>>a[i];
        b[a[i]%2]++;
    }
    if(b[0]>=2 && b[1]>=1){
        cout<<"YES\n";
        ll cont0=0,cont1=0;
        FOR(i,0,n){
            if((a[i]%2)==0 && cont0<2){
                cout<<i+1<<" ";
                cont0++;
            }
            else if((a[i]%2)==1 && cont1<1){
                cout<<i+1<<" ";
                cont1++;
            }
        }
        cout<<"\n";

    }
    else if(b[1]>=3){
        cout<<"YES\n";
        ll cont1=0;
        FOR(i,0,n){
            if((a[i]%2)==1 && cont1<3){
                cout<<i+1<<" ";
                cont1++;
            }
        }
        cout<<"\n";
    }
    else{
        cout<<"NO\n";
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








