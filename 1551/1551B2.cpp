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
    ll n,k;
    cin>>n>>k;
    map <ll,vll> ma;
    ll x;
    FOR(i,0,n){
        cin>>x;
        if(ma[x].size()<k){
            ma[x].push_back(i);
        }
    }
    ll sum=0;
    for(auto e: ma){
        sum+=e.se.size();
    }
    sum-=sum%k;
    vll a(n,0);
    ll color=0;
    bool ok=true;
    for(auto e : ma){
        if(!ok) break;
        for(auto i : e.se){
            a[i]=++color;
            color%=k;
            if(--sum==0){
                ok=false;
                break;
            }
        }
    }
    FOR(i,0,n){
        cout<<a[i]<<" ";
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








