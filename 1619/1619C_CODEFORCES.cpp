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
    ll a,s;
    cin>>a>>s;
    vector<ll> r;
    while(s){
        int x=a % 10;
        int y=s % 10;
        if(x<=y) {r.emplace_back(y-x);}
        else{
            s/=10;
            y+=10*(s%10);
            if(x < y && y>= 10 && y <= 19){
                r.emplace_back(y-x);

            }
            else{
                cout<<"-1\n";
                return;
            }
        }
        a/=10;
        s/=10;
    }
    if(a){
        cout<<"-1\n";
        return;
    }
    else{
        while(r.back()==0)
            r.pop_back();
        for(int i=r.size()-1;i>=0;i--){
            cout<<r[i];
        }
        cout<<"\n";
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
