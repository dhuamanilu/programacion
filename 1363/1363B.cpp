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
    vector <ll> cont0(n,0),cont1(n,0);
    cont0[0]=(s[0]=='0');
    cont1[0]=(s[0]=='1');
    FOR(i,1,n){
        cont0[i]=cont0[i-1]+(s[i]=='0');
        cont1[i]=cont1[i-1]+(s[i]=='1');
    }
    ll ans=LONG_LONG_MAX;
    FOR(i,0,n){
        ll aux=i+1-(cont1[i])+n-i-1-(cont0[n-1]-cont0[i]);
        ll aux2=i+1-(cont0[i])+n-i-1-(cont1[n-1]-cont1[i]);
        //cout<<"este es aux2: "<<i+1-cont0[i]<<" "<<n-i-1-(cont1[n-1]-cont1[i])<<"\n";
        ll res=min(aux,aux2);
        ans=min(ans,res);
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








