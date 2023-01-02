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
ll maxi=LONG_LONG_MIN;
vector <ll> ans;
void solve(){
    string str;
    ll sum=0;
    while(getline(cin, str)){
        if(str.length()==0 ) break;
        sum+=stol(str);
    }
    //cout<<"este es mi sum:"<<sum<<"\n";
    ans.push_back(sum);


}
int main(){
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
    int t=2000;
    //cin>>t;
    while(t--){
        solve();
    }
    sort(all(ans));
    reverse(all(ans));
    cout<<ans[0]+ans[1]+ans[2]<<"\n";
    return 0;
}








