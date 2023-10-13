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
vector<long long> factorize(long long n) {
    vector<long long> factorization;
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}
void solve(){
    ll x;
    cin>>x;
    auto vec=factorize(x);
    map<ll,ll> m;
    for(auto & e : vec){
        m[e]++;
    }
    for(auto & e: m){
        cout<<e.f<<" "<<e.se<<"\n";
    }

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen("hola.in", "r")) {
		freopen("hola.in", "r", stdin);
		freopen("ansgus.in", "w", stdout);
    }
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}








