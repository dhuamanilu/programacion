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

struct Punto{

    int x;
    int y;

};
void solve(){
    Punto a,b,c;
    cin>>a.x>>a.y;
    cin>>b.x>>b.y;
    cin>>c.x>>c.y;
    if(a.y == b.y && c.y < a.y){
        if(a.y == 0 ){
            cout<<"0.00000\n";
            return;
        }
        cout<<abs(a.x-b.x)<<"\n";
    }
    else if(a.y == c.y && b.y < a.y){
        if(a.y == 0 ){
            cout<<"0.00000\n";
            return;
        }
        cout<<abs(a.x-c.x) <<"\n";
    }
    else if(b.y == c.y && a.y < b.y){
        if(b.y == 0 ){
            cout<<"0.00000\n";
            return;
        }
        cout<< abs(b.x-c.x)<<"\n";
    }
    else{
        cout<<"0.00000\n";
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
