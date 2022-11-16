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
    ll a[n];
    FOR(i,0,n){
        cin>>a[i];
    }
    vector <string> ans;
    ans.push_back(string (a[0],'a'));
    FOR(i,1,n){
        string aux;
        if(a[i]<ans[i-1].size()){
            aux=ans[i-1].substr(0,a[i]);
        }
        else{
            string b(a[i]-(int) ans[i-1].size(),'b');
            aux=ans[i-1]+b;
        }
        ans.push_back(aux);
    }
    if(a[n-1]<ans[n-1].size()){
        ans.push_back(ans[n-1].substr(0,a[n-1]));
    }
    else{
        string baux(a[n-1]-(int)ans[n-1].size(),'b');
        ans.push_back(ans[n-1]+baux);
    }
    for(auto e : ans){
        cout<<e<<"\n";
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








