#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map <ll,ll> mll;
typedef vector <pair<ll,ll>> vpll;
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
    ll a[n][5];
    FOR(i,0,n){
        FOR(j,0,5){
            cin>>a[i][j];
        }
    }
    ll pos=0;
    FOR(i,0,n){
        ll cnt=0;
        FOR(j,0,5){
            if(a[pos][j]<a[i][j]){
                cnt++;
            }
        }
        if(cnt>=3){
            continue;
        }
        else{
            pos=i;
        }
    }

    FOR(i,0,n){
        if(i==pos) continue;
        ll cont=0;
        FOR(j,0,5){
            if(a[pos][j]<a[i][j]){
                cont++;
            }
        }
        if(cont>=3){
            continue;
        }
        else{
            cout<<"-1\n";
            return;
        }
    }
    cout<<pos+1<<"\n";
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








