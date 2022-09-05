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
ll eval(ll a){
    return a*(a+1)/2;
}
void solve(){
    ll k,x;
    cin>>k>>x;
    ll s=0,e=2*k,m=s+(e-s)/2;
    if(k*k<=x){
        cout<<2*k-1<<"\n";
        return;
    }
    while(s<=e){
        ll aux=0;
        m=s+(e-s)/2;
        if(m<k){
            aux=eval(m);
        }
        else{
            aux=eval(k-1)+eval(k)-eval(2*k-1-m);
        }
        if(aux<x){
            s=m+1;
        }
        else{
            e=m-1;
        }
    }
    cout<<s<<"\n";

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








