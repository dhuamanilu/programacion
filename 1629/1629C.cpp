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
    vector <ll> a(n),ms(n);
    FOR(i,0,n){
        cin>>a[i];
    }
    ll cm=0;
    vector <ll> found(n+1);
    for(ll i=n-1;i>=0;i--){
        found[a[i]]=1;
        while(found[cm]) cm++;
        ms[i]=cm;
    }
    vector <ll> cont(n+1),ans;
    FOR(i,0,n){
        ans.push_back(ms[i]);
        ll j=i,am=0,ok=0;
        while(!ok){
            cont[a[j]]++;
            while(cont[am]) am++;
            if(am==ms[i]){
                ok=1;
            }
            j++;
        }
        FOR(l,i,j){
            cont[a[l]]--;
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








