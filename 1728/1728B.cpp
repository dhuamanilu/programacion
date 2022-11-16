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
    vector <ll> a(n);
    if(n%2==0){
        ll aux=n-2;
        FOR(i,0,n-3){
            a[i]=aux;
            aux--;
        }
        a[n-3]=1;
        a[n-2]=n-1;
        a[n-1]=n;
    }
    else{
        a[0]=1;
        ll aux=n-2;
        FOR(i,1,n-2){
            a[i]=aux;
            aux--;
        }
        a[n-2]=n-1;
        a[n-1]=n;
    }

    FOR(i,0,n){
        cout<<a[i]<<" ";
    }
    cout<<"\n";

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







