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
    ll a[n];
    set <ll> s1;
    FOR(i,0,n){
        cin>>a[i];
        s1.insert(a[i]);
    }
    vll b(n),c(n);
    b[0]=a[0];
    c[0]=a[0];
    set<ll> s;
    FOR1(i,1,n){
        s.insert(i);
    }
    for(auto e :s1){
        s.erase(e);
    }
    FOR(i,1,n){
        if(a[i]>a[i-1]){
            b[i]=a[i];
            c[i]=a[i];
        }
        else{
            auto x=s.lower_bound(1ll);
            b[i]=*x;
            s.erase(x);
        }
    }
    for(auto e : b){
        cout<<e<<" ";
    }
    cout<<"\n";
    s.clear();
    FOR1(i,1,n){
        s.insert(i);
    }
    for(auto e :s1){
        s.erase(e);
    }
    ll last=c[0];
    FOR(i,1,n){
        if(a[i]>a[i-1]){
            c[i]=a[i];
            last=c[i];
        }
        else{
            auto x=--s.lower_bound(last);
            //cout<<*x<<"\n";
            c[i]=*x;
            s.erase(x);
        }
    }
    for(auto e: c){
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








