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

bool check(vector <ll> &cont,ll m){
    ll ans=0,fr=0;
    FOR(i,0,cont.size()){
        if(m>=cont[i]){
            fr+=(m-cont[i])/2;
        }
        else
    }
}
ll bb(vector <ll> &cont,ll m){
    ll s=0,e=2*m,mid=s+(e-s)/2,res=-1;
    while(s<=e){
        mid=s+(e-s)/2;
        if(check(cont,mid)) {
            res=m;
            e=m-1;
        }
        else{
            s=m+1;
        }
    }
    return res;
}
void solve(){
    ll n,m;
    cin>>n>>m;
    vector <ll> a(m);
    FOR(i,0,m){
        cin>>a[i];
        a[i]--;
    }
    vector<ll> cont(n,0);
    FOR(i,0,n){
        cont[a[i]]++;
    }
    cout<<bb(cont,m)<<"\n";
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








