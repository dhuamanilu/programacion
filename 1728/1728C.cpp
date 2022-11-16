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
ll f(ll a){
    ll x=0;
    while(a>0){
        a/=10;
        x++;
    }
    return x;
}
void solve(){
    ll n;
    cin>>n;
    priority_queue <ll> a;
    FOR(i,0,n){
        ll x;
        cin>>x;
        a.push(x);
    }
    priority_queue <ll> b;
    FOR(i,0,n){
        ll x;
        cin>>x;
        b.push(x);
    }
    ll ans=0;
    while(!a.empty()){
        ll x=a.top(),y=b.top();
        if(x==y){
            a.pop();
            b.pop();
        }
        else if(x<y){
            y=f(y);
            ans++;
            b.pop();
            b.push(y);
        }
        else{
            x=f(x);
            ans++;
            a.pop();
            a.push(x);
        }

    }

    cout<<ans<<"\n";
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








