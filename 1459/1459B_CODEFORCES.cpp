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
const int MAXN = 100010;
set<pair<ll,ll>> s;
ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};
ll n;
void go(bool primera,ll x,ll y,ll cont,bool ultima){
    if(cont==n){
        s.insert(mp(x,y));
        return;
    }
    if(primera){
        FOR(i,0,4){
            if(i<2)
                go(false,x+dx[i],y+dy[i],cont+1,true);
            else
                go(false,x+dx[i],y+dy[i],cont+1,false);
        }
    }
    else{
        if(ultima){
            go(false,x,y-1,cont+1,false);
            go(false,x,y+1,cont+1,false);
        }
        else{
            go(false,x+1,y,cont+1,true);
            go(false,x-1,y,cont+1,true);
        }
    }

}
void solve(){
    cin>>n;
    ll var1=1+(3*n*(n+4)+2- (pow(-1,n)*(n*(n+4)+2)))/8;
    cout<<var1<<"\n";
    /*go(true,0,0,0,true);
    cout<<s.size()<<"\n";*/
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  	int t=1;
  	while(t--){
        solve();
  	}
	return 0;
}
