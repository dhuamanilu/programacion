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
    ll maxi=LONG_LONG_MIN;
    FOR(i,0,n){
        cin>>a[i];
        maxi=max(maxi,a[i]);
    }
    bool ok=true;
    FOR(i,0,n-1){
        if((a[i]&a[i+1])==a[i]) continue;
        else{
            ok=false;
            break;
        }
    }
    if(ok){
        FOR(i,0,n){
            cout<<"0 ";
        }
        cout<<"\n";
        return;
    }
    vector <ll> b(n,0);
    vector <ll> gro(n,0);
    b[0]=0;
    gro[0]=a[0];
    FOR(i,1,n){
        b[i]=(gro[i-1]|a[i])^a[i];
        gro[i]=a[i]^b[i];
    }
    FOR(i,0,n){
        cout<<b[i]<<" \n"[i==n-1];
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








