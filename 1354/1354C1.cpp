#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i=a; i<(b); i++)
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
float polyapothem(float n, float a){
    // Side and side length cannot be negative
    if (a < 0 && n < 0)
        return -1;
    // Degree converted to radians
    return a / (2 * tan((180 / n) * 3.14159265358979323846 / 180));
}
void solve(){
	ll n;
	cin>>n;
    cout<<std::fixed<<std::setprecision(8)<<2*polyapothem(2*n,1)<<"\n";
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
