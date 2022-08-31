#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
#define FOR(i, a, b) for (long long i=a; i<(b); i++)
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
    deque<ll> dq;
    for(ll i=1;i<=n;i++){
        ll auxi;
        cin>>auxi;
        dq.push_back(auxi);
    }
    ll res[n+1];

    for(ll i=n;i>=1;i--){
        ll cont=0;
        while(dq.back()!=i){
            ll auxi=dq.front();
            dq.pop_front();
            dq.push_back(auxi);
            cont++;
        }
        dq.pop_back();
        res[i]=cont;
    }
    for(ll i=1;i<=n;i++){
        cout<<res[i]<<" ";
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








