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
    ll s=0;
    FOR(i,0,n){
        cin>>a[i];
        s+=a[i];
        f[a[i]]++;
    }
    if( ((2*s) % n) !=0){
        cout<<"0\n";
        return;
    }
    else{
        ll resto=(2*s)/n,ans=0;
        FOR(i,0,n){
            ll auxi=resto-a[i];
            if(f.count(auxi)!=0){
                ans+=f[auxi];
                //cout<<"ans : "<<ans<<"\n";
            }
            if(a[i]==resto-a[i]){
                //cout<<"me restare 1: "<<a[i]<<" "<<resto-a[i]<<"\n";
                ans--;
            }
        }
        cout<<ans/2<<"\n";
        return;
    }


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
