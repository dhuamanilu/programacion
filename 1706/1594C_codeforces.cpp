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
    char c;
    cin>>c;
    string s;
    cin>>s;

    bool ok=true,imp=false,par=false;
    for(int i=1;i<=n;i++){
        if(s[i-1]==c) continue;
        else{
            ok=false;
            if(i%2==0){
                imp=true;
            }
            else{
                par=true;
            }
        }
    }
    if(ok){
        cout<<"0\n";
        return;
    }
    if((imp && !par) || (!imp &&par)){
        cout<<"1\n";
        if(imp){
            cout<<"2\n";
            return;
        }
        else if(par){

        }
        return;
    }
    if(par && imp){
        cout<<"2\n";
        cout<<n<<" "<<n-1<<"\n";

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
