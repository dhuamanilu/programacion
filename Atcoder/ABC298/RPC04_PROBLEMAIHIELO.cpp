#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map <ll,ll> mll;
typedef vector <pair<ll,ll>> vpll;
typedef priority_queue<ll> pq;
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
#define n_l '\n'
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;
const int N=1000+3;

void solve(){
    ll n,k;
    cin>>n>>k;
    vll a(n);
    ll sumPos=0,sumNeg=0;
    FOR(i,0,n){
        cin>>a[i];
        if(a[i]>=0) sumPos+=a[i];
        else sumNeg+=abs(a[i]);
    }
    vll b(k);
    FOR(i,0,k){
        cin>>b[i];
    }
    vector<double> alt(n);
    ll sum=0;
    FOR(i,0,n){
        sum+=a[i];
        if(sum<0){
            alt[i]=(1.0*sum)/(-5.0);
        }
        else{
            alt[i]=0;
            sum=0;
        }
    }
    /*for(auto & e : alt){
        cout<<e<<" ";
    }
    cout<<"\n";*/
    sort(all(alt));
    FOR(i,0,k){
        auto x=lower_bound(all(alt),b[i]);
        if(x==alt.end()){
            cout<<"0 ";
        }
        else{
            ll num=x-alt.begin();
            cout<<n-num<<" ";
        }
    }

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}








