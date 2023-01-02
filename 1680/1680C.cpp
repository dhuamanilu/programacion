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
bool revisa(){


}
void solve(){
    string s;
    cin>>s;
    ll n=s.size();
    vll a(n,0);
    a[0]=(s[0]=='1');
    FOR(i,1,n){
        a[i]=a[i-1]+(s[i]=='1');
    }
    if(a[n-1]==0 || a[n-1]==n){
        cout<<"0\n";
        return;
    }
    ll st=0,e=n,m=st+(e-st)/2;
    while(st<=e){
        m=st+(e-st)/2;
        if(revisa()){

        }
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








