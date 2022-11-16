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
    ll n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector <ll> cont(26,0);
    ll a[m];
    FOR(i,0,m){
        cin>>a[i];
    }
    vector < vector <ll > > aux(n,vector <ll>(26,0) );
    aux[0][s[0]-'a']++;
    FOR(i,1,n){
        vector <ll> get;
        get=aux[i-1];
        get[s[i]-'a']++;
        aux[i]=get;
    }
    FOR(i,0,m){
        FOR(j,0,26){
            cont[j]+=aux[a[i]-1][j];
        }
    }
    for(auto e : s){
        cont[e-'a']++;
    }
    for(auto e : cont){
        cout<<e<<" ";
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








