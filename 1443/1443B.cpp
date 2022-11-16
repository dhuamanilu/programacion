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
    ll a,b;
    cin>>a>>b;
    string s;
    cin>>s;
    vll pos;
    FOR(i,0,s.size()){
        if(s[i]=='1'){
            pos.emplace_back(i);
        }
    }
    if(pos.size()==0){
        cout<<"0\n";
        return;
    }
    ll ans=a;
    FOR(i,0,pos.size()-1){
        ans+=min( (pos[i+1]-pos[i]-1)*b ,a);
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








