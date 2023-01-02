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
    ll n,k;
    cin>>n>>k;
    ll a[n];
    string num="";
    FOR(i,0,n){
        cin>>a[i];
        num+=to_string(a[i]);
    }
    FOR(i,0,k){
        string ans="0";
        ll j=n;
        while(j>=0){
            string aux="";
            string parte1=num.substr(0,j);
            string parte2="";
            if(j+1<n){
                parte2=num.substr(j+1);
            }
            aux=parte1+parte2;
            ans=max(ans,aux);
            j--;
        }
        num=ans;
    }
    cout<<num<<"\n";
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
