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
const int MX = 1000005;
const int N=1000+3;
set <ll> primos;
bool isPrime(ll a){
    for(ll i=2;i*i<=a;i++){
        if(a%i==0) return false;
    }
    return true;
}
void solve(){
    ll n,ele;
    cin>>n;
    FOR(i,0,n){
        cin>>ele;
        if(primos.find(ele)!=primos.end()){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n=1000000;
    primos.insert(4);
    for(ll i=3;i<=n;i++){
        if(isPrime(i)){
            primos.insert(i*i);
        }
    }
    solve();
    return 0;
}








