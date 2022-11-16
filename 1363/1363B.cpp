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
    string s;
    cin>>s;
    ll n=s.size();
    vll cont(n,0);
    vll cont0(n,0);
    FOR(i,1,n){
        cont[i]=cont[i-1]+(s[i]=='1');
        cont0[i]=cont0[i-1]+(s[i]=='0');
    }
    ll suff1=cont[n-1],suff0=cont0[n-1];
    ll ans=min(cont[n-1],);
    FOR(i,0,n){
        suff1-=(s[i]=='1');
        suff0-=(s[i]=='0');
        ans=min(ans,cont+suff1);
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








