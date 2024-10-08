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
    vector <ll> a(n),mex(n);
    FOR(i,0,n){
        cin>>a[i];
    }

    ll act=0;
    vll cont(n+1,0);
    for(ll i=n-1;i>=0;i--){
        cont[a[i]]++;
        while(cont[act]) act++;
        mex[i]=act;
    }
    vll ans;
    vll found(n+1,0);

    FOR(i,0,n){
        ans.pb(mex[i]);
        ll j=i,mex2=0;
        while(j<n){
            found[a[j++]]++;
            while(found[mex2]) mex2++;
            if(mex2==mex[i]){
                break;
            }

        }
        FOR(k,i,j){
            found[a[k]]--;
        }
        i=j-1;
    }
    cout<<ans.size()<<"\n";
    for(auto e : ans){
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
