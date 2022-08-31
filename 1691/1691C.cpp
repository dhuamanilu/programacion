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
    string s;
    cin>>s;
    ll cont=0,ind=-1;
    bool guarda=false;
    FOR(i,0,n){
        cont+=s[i]-'0';
        if(s[i]=='1' && !guarda){
            guarda=true;
            ind=i;
        }
    }
    guarda=false;
    ll ind2=-1;
    for(ll i=n-1;i>=0;i--){
        if(s[i]=='1' && !guarda){
            guarda=true;
            ind2=i;
            break;
        }
    }
    ll res=0;

    if(cont>0 && k>=n-1-ind2 ){
        k-=(n-1-ind2);
        res++;
        cont--;
    }
    if(cont>0 && k>=ind ){
        k-=ind;
        res+=10;
        cont--;
    }
    cout<<11*cont+res<<"\n";
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








