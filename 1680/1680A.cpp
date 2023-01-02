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
    ll l1,r1,l2,r2;
    cin>>l1>>r1>>l2>>r2;
    if(r1<r2){
        if(l2<=r1){
            cout<<max(l1,l2)<<"\n";
        }
        else{
            cout<<l1+l2<<"\n";
        }
    }
    else{
        if(l1<=r2){
            cout<<max(l1,l2)<<"\n";
        }
        else{
            cout<<l1+l2<<"\n";
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








