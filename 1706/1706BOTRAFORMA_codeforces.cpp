
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

void solve(){
    int n;
    cin>>n;
    int a[n];
    map <int,int> f;
    FOR(i,0,n){
        cin>>a[i];
        f[a[i]]++;
    }
    if(n==1){
        cout<<"1\n";
        return;
    }
    for(int i=1;i<=n;i++){
        if(f.count(i)){
            cout<<f[i]<<" ";
        }
        else{
            cout<<"0 ";
        }
    }
    cout<<"\n";




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
