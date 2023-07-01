#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


typedef pair<int, int> pi;

typedef vector<int> vi;
typedef vector<ll> vll;
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
const int MAXN = 100010;

bool go(ll n, ll m ,ll k ,vector <ll>  &a){

    ll cont=0;
    bool usar=false;
    FOR(i,0,k){
        if((a[i] / n) >=2){
            cont+=(a[i] / n);
        }
        if((a[i] / n) > 2){
            usar=true;
        }
    }
    if(cont>=m && (usar || m%2==0)){
        return true;
    }
    usar=false;
    cont=0;
    FOR(i,0,k){
        if((a[i] / m) >=2){
            cont+=(a[i] / m);
        }
        if((a[i] / m) >2){
            usar=true;
        }
    }
    if(cont>=n && (usar || n%2==0)){
        return true;
    }
    return false;
}
void solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> a(k);
    FOR(i,0,k){
        cin>>a[i];
    }
    if (go(n,m,k,a)){
        cout<<"YES\n";
    }
    else{
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
