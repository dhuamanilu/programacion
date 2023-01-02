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
    ll n,U,R,D,L;
    cin>>n>>U>>R>>D>>L;
    FOR(i,0,1<<4){
        ll nU=U,nR=R,nD=D,nL=L;
        if(i&1){
            nU--;
            nL--;
        }
        if(i&2){
            nU--;
            nR--;
        }
        if(i&4){
            nD--;
            nL--;
        }
        if(i&8){
            nD--;
            nR--;
        }
        if(min(min(nU,nR),min(nD,nL))>=0 && max(max(nU,nR),max(nD,nL))<=n-2){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";


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








