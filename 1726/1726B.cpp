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
    ll n,m;
    cin>>n>>m;
    if(m<n){
        cout<<"NO\n";
        return;
    }
    if((n-1)%2==0){
        cout<<"YES\n";
        FOR(i,0,n-1){
            cout<<"1 ";
        }
        cout<<m-n+1<<"\n";
        return;
    }
    else{

        if((m-n+2)%2==0){
            cout<<"YES\n";
            FOR(i,0,n-2){
                cout<<"1 ";
            }
            cout<<(m-n+2)/2<<" "<<(m-n+2)/2<<"\n";
        }
        else{
            cout<<"NO\n";
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








