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
const int MX = 100005;
const int N=1000+3;
vector <ll> win[100005];
ll eval(ll a,ll b){
    return upper_bound(win[a].begin(),win[a].end(),b)-win[a].begin();
}
void solve(){
    ll n,q;
    cin>>n>>q;
    vector<ll> a(n+1);
    ll ind=1;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    deque<ll> dq;
    for(ll i=2;i<=n;i++){
        dq.push_back(i);
    }
    ll cur=1;
    for(ll i=1;i<=n;i++){
        win[i].clear();
    }
    for(ll i=1;i<=n;i++){
        if(a[cur]>a[dq.front()]){
            win[cur].push_back(i);
            ll auxi=dq.front();
            dq.pop_front();
            dq.push_back(auxi);
        }
        else{
            win[dq.front()].push_back(i);
            dq.push_back(cur);
            cur=dq.front();
            dq.pop_front();
        }
    }
    FOR(j,0,q){
        ll i,k;
        cin>>i>>k;
        if(k<=n){
            cout<<eval(i,k)<<"\n";
        }
        else{
            cout<<eval(i,k)+(a[i]==n ? k-n:0)<<"\n";
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








