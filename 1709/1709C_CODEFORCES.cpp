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
    string s;
    cin>>s;
    ll cont1=0,ap=0,cie=0,n=s.length();
    FOR(i,0,n){
        if(s[i]=='?') cont1++;
        else if(s[i]=='(') ap++;
        else cie++;
    }

    ll resta=-1*(ap-cie);
    ll apertura=(resta+cont1)/2;
    ll cierre=(cont1-resta)/2;
    if(apertura==0 || cierre ==0){
        cout<<"YES\n";
        return;
    }
    string a=string(apertura-1,'(')+')'+'('+string(cierre-1,')');
    ll co=0;
    //cout<<"ete es a : "<<a<<"\n";
    FOR(i,0,n){
        if(s[i]=='?'){
            s[i]=a[co++];
        }
    }
    ll revisa=0;
    FOR(i,0,n){
        if(s[i]=='('){
           revisa++;
        }
        else revisa--;
        if(revisa<0){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
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
