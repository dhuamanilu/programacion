#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map <ll,ll> mll;
typedef vector <pair<ll,ll>> vpll;
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
<<<<<<< HEAD
    ll a[n];
    ll xo=0;
=======
    vll a(n);
>>>>>>> 7516ba663e5ba0b6c491e407db6d8ab0812f5cd1
    FOR(i,0,n){
        cin>>a[i];
    }
    vll pref(n,0);
    pref[0]=a[0];
    FOR(i,1,n){
        pref[i]=pref[i-1]^a[i];
    }
    if(pref[n-1]==0){
        cout<<"YES\n";
    }
    else{
        FOR(i,0,n){
            FOR(j,i+1,n){
                ll xo1=pref[i],restar1=i>=1 ? pref[i-1] : 0ll;
                ll xo2=pref[j]^restar1,restar2=j>=1 ? pref[j-1] : 0ll;
                ll xo3=pref[n-1]^restar2;
                if(xo1==xo2 && xo2==xo3){
                    cout<<"YES\n";
                    return;
                }
            }
        }
        cout<<"NO\n";
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








