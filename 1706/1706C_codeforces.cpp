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

    FOR(i,0,n){
        cin>>a[i];
    }
    int cont1=0;
    for(int i=1;i<n;i+=2){
        if(i!=n-1 && i!=0){
            if(a[i]>a[i+1] && a[i]>a[i-1]) continue;
            cont1+=max(a[i+1],a[i-1])+1-a[i];
        }
    }
    int cont2=0;
    for(int i=2;i<n;i+=2){
        if(i!=n-1 && i!=0){
            if(a[i]>a[i+1] && a[i]>a[i-1]) continue;
            cont2+=max(a[i+1],a[i-1])+1-a[i];
        }
    }
    cout<<"cont (1 y 2) : "<<cont1<<" "<<cont2<<"\n-----------\n";

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
