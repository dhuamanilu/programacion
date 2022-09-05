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
int n,m;
bool isValid(int a,int b){
    return a>=0 && a<n && b>=0 && b<n;
}
void solve(){
	cin>>n>>m;
	vector<vector<char>> a (n,vector<char>(m));
    vector<vector<char>> r (n,vector<char>(m,'-'));
	FOR(i,0,n){
		FOR(j,0,m){
			cin>>a[i][j];   
		}
	}
    FOR(i,0,n){
		FOR(j,0,m){
			if(a[i][j]!='-'){
                if((i +j ) & 1 )
                    a[i][j]='W';
                else
                    a[i][j]='B';
            }   
		}
	}
    FOR(i,0,n){
		FOR(j,0,m){
			cout<<a[i][j];   
		}
        cout<<nl;
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
    //cin>>t;

  	while(t--){
        solve();
  	}
	return 0;
}