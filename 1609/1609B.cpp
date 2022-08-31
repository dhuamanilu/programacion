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
ll is(string &s,ll i ,ll n){
    if(i+2>=n || i<0) return 0;
    return s[i]=='a' && s[i+1]=='b' && s[i+2]=='c';
}
void solve(){
    ll n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    ll cont=0;
    FOR(i,0,n-2){
        string auxi=s.substr(i,3);
        if(auxi=="abc"){
           cont++;
        }
    }
    //cout<<"cont antes de las querys : "<<cont<<"\n";
    while(q--){
        ll i;
        char c;
        cin>>i>>c;
        i--;
        cont-=is(s,i-2,n)+is(s,i-1,n)+is(s,i,n);
        s[i]=c;
        cont+=is(s,i-2,n)+is(s,i-1,n)+is(s,i,n);
        cout<<cont<<"\n";

    }
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








