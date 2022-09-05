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
    ll n,k,r,c;
    cin>>n>>k>>r>>c;
    if(k==1){
        FOR(i,0,n){
            FOR(j,0,n){
                cout<<"X";
            }
            cout<<"\n";
        }
        return;
    }
    else{
        FOR1(i,1,n){
            FOR1(j,1,n){
                if((i+j)%k == (r+c)%k){
                    cout<<"X";
                }
                else{
                    cout<<".";
                }

            }
            cout<<"\n";
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








