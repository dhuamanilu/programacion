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
    ll a[n];
    ll ind=-1,maxi=LONG_LONG_MIN;
    FOR(i,0,n){
        cin>>a[i];
        if(a[i]>maxi){
            maxi=a[i];
            ind=i;
        }
    }

    ll sum=0;
    ll indl=ind,indr=ind;
    while(indl>=1 && a[indl-1]>=0){
        indl--;
    }
    while(indr<n-1 && a[indr+1]>=0){
        indr++;
    }
    FOR1(i,indl,indr){
        sum=max(sum,sum+a[i]);
    }

    cout<<"ESTA ES LA SUMA Y EL IND : "<<sum<<" "<<indl<<" "<<indr<<"\n";
    FOR(i,0,n+1){
        cout<<sum<<" \n"[i==n];
        if(indl >=1 && sum+a[indl-1] > sum && sum+a[indl-1]>sum+a[indr+1] ){
            sum+=a[indl-1]+x;
            indl--;
        }
        else if(indr<n-1 && sum+a[indr+1]>sum && sum+a[indr+1] > sum+a[indl-1]){
            sum+=a[indr+1]+x;
            indr++;
        }
        else{
            continue;
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








