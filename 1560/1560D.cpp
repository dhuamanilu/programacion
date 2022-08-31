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

ll eval(string str,string val){
    ll ind1=0,ind2=0;
    ll taken=0;
    while(ind1<str.length() && ind2<val.length()){
        if(str[ind1]==val[ind2]){
            taken++;
            ind1++;
            ind2++;
        }
        else{
            ind1++;
        }
    }
    return str.length()+val.length()-2*taken;
}
void solve(){
    ll n;
    cin>>n;
    ll ans=LONG_LONG_MAX;
    vector <string> res;
    for(ll i=1;i<=(2e18);i*=2){
        res.emplace_back(to_string(i));
    }
    string str=to_string(n);
    FOR(i,0,res.size()){
        ans=min(ans,eval(str,res[i]));
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








