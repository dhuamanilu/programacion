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
#define FORR(i,a,b) for (long long i=a; i>=(b); i--)
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
    ll a[n];
    FOR(i,0,n){
        cin>>a[i];
    }
    priority_queue<ll, vector<ll>, greater<ll> > q;
    ll sum=0,ans=0;
    FOR(i,0,n-m){
        ll norm=i+m;
        if(a[norm]<0) q.push(a[norm]);
        sum+=a[norm];
        while(true){
            if(sum>=0) break;
            ans++;
            ll to=q.top();
            q.pop();
            sum+=-2*to;
        }
    }
    if(a[m-1]<=0){
        sum=a[m-1];
    }
    else if(m!=1){
        sum=-1*a[m-1];
        ans++;
    }
    priority_queue<ll, vector<ll>> q2;
    FORR(i,m-2,1){
        if(a[i]>0) q2.push(a[i]);
        sum+=a[i];
        while(sum>0){
            ans++;
            ll to=q2.top();
            q2.pop();
            sum+=-2*to;
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








