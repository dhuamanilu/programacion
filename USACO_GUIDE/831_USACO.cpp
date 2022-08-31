#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


typedef pair<int, int> pi;

typedef vector<int> vi;
typedef vector<ll> vll;
#define FOR(i, a, b) for (long long i=a; i<(b); i++)

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
    vector <string> a;
    FOR(i,0,3){
        string s;
        cin>>s;
        a.push_back(s);
    }
    /*int res1=0,res2=0;
    FOR(i,0,3){
        int auxi=0;
        char c=a[i][0];
        FOR(j,1,3){
            if(a[i][j]==c){
                auxi++;
            }
        }
        if(auxi==2){
            res1++;
        }
    }
    FOR(i,0,3){
        int auxi=0;
        char c=a[0][i];
        FOR(j,1,3){
            if(a[j][i]==c){
                auxi++;
            }
        }
        if(auxi==2){
            res1++;
        }
    }
    if(a[0][0]==a[1][1] && a[1][1]==a[2][2]){
        res1++;
    }
    if(a[2][0]==a[1][1] && a[1][1]==a[0][2]){
        res1++;
    }
    cout<<res1<<"\n"<<res2<<"\n";*/
}
int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    /*if (fopen("tttt.in", "r")) {
		freopen("tttt.in", "r", stdin);
		freopen("tttt.out", "w", stdout);
    }*/
  	int t=1;
    cin>>t;

  	while(t--){
        solve();
  	}
	return 0;
}








