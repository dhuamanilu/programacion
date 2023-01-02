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
    ll ans=LONG_LONG_MAX;
    FOR(i,0,n){
        vector <ll> cont(3,0);
        for(ll j=i;j<min(i+7,n);j++){
            cont[s[j]-'a']++;
            if(cont[0]>cont[1] && cont[0]>cont[2] && cont[0]+cont[1]+cont[2]>=2){
                ans=min(ans,j-i+1);
            }
        }
    }
    if(ans==LONG_LONG_MAX){
        cout<<"-1\n";
    }
    else{
        cout<<ans<<"\n";
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








