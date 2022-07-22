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
    int n,m;
    cin>>n>>m;
    int a[n];
    FOR(i,0,n){
        cin>>a[i];

    }
    string s(m,'B');
    FOR(i,0,n){
        //cout<<"este es s acutal :"<<s<<"\n";
        if(a[i]-1 <= m-a[i]){
            if(s[a[i]-1]=='A'){
                s[m-a[i]]='A';
            }
            s[a[i]-1]='A';
        }
        else{
            if(s[m-a[i]]=='A'){
                s[a[i]-1]='A';
            }
            s[m-a[i]]='A';
        }
    }
    cout<<s<<"\n";



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
