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
    ll cost=abs(s[n-1]-s[0]);
    cout<<cost<<" ";
    char st=s[0],e=s[n-1];
    map <char ,vector <ll > > m;
    FOR(i,0,n){
        m[s[i]].push_back(i);
    }
    vector <ll> ans;

    while(true){
        for(auto e : m[st]){
            ans.push_back(e);
        }
        if(st<e)st++;
        else if(st>e){
            st--;
        }
        else break;
    }
    cout<<ans.size()<<"\n";
    for(auto e : ans){
        cout<<e+1<<" ";
    }
    cout<<"\n";


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








