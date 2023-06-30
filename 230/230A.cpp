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
bool customCompare(const pair<ll,ll>& a, const pair<ll,ll>& b) {
    // Ordenar por el menor del primer elemento
    if (a.first != b.first) {
        return a.first < b.first;
    }

    // Ordenar por el mayor del segundo elemento
    return a.second > b.second;
}

void solve(){
    ll s,n;
    cin>>s>>n;
    vector<pair<ll,ll>> x(n);
    FOR(i,0,n){
        cin>>x[i].first>>x[i].second;
    }
    sort(all(x),customCompare);
    FOR(i,0,n){
        if(s > x[i].f){
            s+=x[i].se;
        }
        else{
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}








