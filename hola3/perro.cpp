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
const int MX = 100001;
const int N=1000+3;

void solve(){
   int n,x;
    cin>>n>>x;
    vector <int> a(2*n);
    FOR(i,0,2*n){
        cin>>a[i];
    }
    sort(all(a));
    int arr1[n];
    int arr2[n];
    FOR(i,0,n){
        arr1[i]=a[i];
    }
    FOR(i,0,n){
        arr2[i]=a[n+i];
    }
    FOR(i,0,n){
        if(arr2[i]-x >= arr1[i]){
            continue;
        }
        else{
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    return;

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    /*if (fopen("abcd.in", "r")) {
		freopen("billboard.in", "r", stdin);
		freopen("billboard.out", "w", stdout);
    }*/
  	int t=1;
    cin>>t;

  	while(t--){
        solve();
  	}
	return 0;
}
