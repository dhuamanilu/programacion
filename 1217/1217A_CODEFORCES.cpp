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
int bb(int str,int in,int fre){
    int s=0,e=fre+1,m=s+(e-s)/2;
    while(s<e){
        m=s+(e-s)/2;
        if((str+m) > in+(fre-m)){
            e=m;
        }
        else{
            s=m+1;
        }
    }
    if(s>fre) return 0;
    return fre-s+1;
}
void solve(){
    int str,in,fre;
    cin>>str>>in>>fre;


    cout<<bb(str,in,fre)<<"\n";



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
