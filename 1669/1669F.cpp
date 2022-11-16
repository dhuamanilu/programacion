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
    vector <ll> suml(n),sumr(n);
    FOR(i,0,n){
        cin>>a[i];
    }
    suml[0]=a[0];
    FOR(i,1,n){
        suml[i]=suml[i-1]+a[i];
    }
    sumr[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--){
        sumr[i]=sumr[i+1]+a[i];
    }
    ll i=0,j=n-1,ans=0;
    while(i<j){
        //cout<<i<<" "<<j<<"\n";
        if(suml[i]==sumr[j]){
            ans=i+1+(n-j);
            i++;
        }
        else if(suml[i]<sumr[j]){
            i++;
        }
        else{
            j--;
        }
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








