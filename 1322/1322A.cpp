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
    ll cont=0,cont2=0;
    FOR(i,0,n){
        if(s[i]=='(') cont++;
        else cont2++;
    }
    if(cont!=n/2 || cont2!=n/2){
        cout<<"-1\n";
        return;
    }
    ll x=0,y=0,ans=0,guarda=0;
    FOR(i,0,n){
        guarda=y;
        if(s[i]=='('){
            x++;
            y++;
        }
        else{
            x++;
            y--;

        }
        if(y<0 || guarda<0) ans++;
    }
    cout<<ans<<" ";

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








