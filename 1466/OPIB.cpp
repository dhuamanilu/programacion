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
    string s;
    cin>>s;
    ll ans=0;
    FOR(i,0,(k+1)/2){
        map<char,ll> m;
        for(ll j=i;j<n;j+=k){
            m[s[j]]++;
        }
        for(ll p=n-i-1;p>=0;p-=k){
            if(k%2==1 && i==k/2) break;
            m[s[p]]++;
        }
        ll maxi=LONG_LONG_MIN;
        for(auto e : m){
            maxi=max(maxi,e.se);
        }
        //cout<<"nmaxi: "<<maxi<<"\n";
        if(k%2==1 && i==k/2){
            ans+=(n/k-maxi);
        }
        else{
            ans+=(n/k*2-maxi);
        }
    }
    cout<<ans<<"\n";

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}








