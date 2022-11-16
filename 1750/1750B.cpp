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
    string s;
    cin>>s;
    ll cont0=0,cont1=0;
    FOR(i,0,n){
        if(s[i]=='0') cont0++;
        else cont1++;
    }
    ll ans=0;
    if(cont1==0){
        ans=cont0*cont0;
    }
    else if(cont0==0){
        ans=cont1*cont1;
    }
    else{
        ans=cont0*cont1;
    }

    FOR(i,0,n){
        ll j=i,cont=0;
        while(s[j]==s[i]){
            j++;
            cont++;
        }
        ans=max(ans,cont*cont);
        i=j-1;
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








