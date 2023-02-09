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
    vll cont(26,0);
    ll sum=0;
    FOR(i,0,n){
        cont[s[i]-'a']++;
    }
    FOR(i,0,26){
        sum+=cont[i];
    }
    ll ans=LONG_LONG_MAX;
    FOR(i,0,26){
        if(sum%cont[i]==0){
            ll aux=0;
            FOR(j,0,26){
                if(cont[i]==cont[j]) continue;
                aux+=cont[j]-cont[i];

            }
            ans=min(ans,aux);
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








