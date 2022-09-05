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
    set <ll>  se;
    for(ll i=1;i*i<=n;i++){
        if(n%(i+1)==0){
            se.insert(i+1);
            n/=(i+1);
        }
        if(n==1) break;
        if((int)se.size()==2){
            se.insert(n);
            n=1;
            break;
        }
    }

    if((int)se.size()!=3){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    for(auto e : se){
        cout<<e<<" ";
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








