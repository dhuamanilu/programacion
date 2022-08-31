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
const int X[]={1,-1,0,0};
const int Y[]={0,0,1,-1};
bool isValid(ll nx,ll ny,ll n,ll m){
    return nx>=0 && nx<n && ny>=0 && ny<m;

}
void GO(vector <vector<ll>> &a,ll m){
    ll ans=0,mini=LONG_LONG_MAX,indI=0,indJ=0;
    ll i=0,j=0;
    FOR(k,0,4){
        ll nx=i+X[k];
        ll ny=j+Y[k];
        if(isValid(nx,ny,2,m)){
            if(nx==i && ny==j-1){
                if(min(a[nx][ny],a[nx+1][ny])<mini){
                    mini=min(mini,min(a[nx][ny],a[nx+1][ny]));
                    indI=i;
                    indJ=j;
                }
            }
            else if(nx==i && ny==j+1){
                if(min(a[nx][ny],a[nx+1][ny])<mini){
                    mini=min(mini,min(a[nx][ny],a[nx+1][ny]));
                    indI=i;
                    indJ=j;
                }
            }
            else if(ny==j && nx==i+1){
                if(min(a[nx][ny],a[nx+1][ny])<mini){
                    mini=min(mini,min(a[nx][ny],a[nx+1][ny]));
                    indI=i;
                    indJ=j;
                }
            }
            else{
                if(min(a[nx][ny],a[nx+1][ny])<mini){
                    mini=min(mini,min(a[nx][ny],a[nx+1][ny]));
                    indI=i;
                    indJ=j;
                }
            }
            //cout<<"ESTOS SON LOS INDI E INDJ LUEGO I Y J : "<<indI<<" "<<indJ<<" "<<i<<" "<<j<<"\n";
        }
        ans+=mini;
    }
    i++;
    j++;

}

void solve(){
    ll m;
    cin>>m;
    vector <vector<ll>> a(2,vector<ll> (m));
    FOR(i,0,2){
        FOR(j,0,m){
            cin>>a[i][j];
        }
    }
    GO(a,m);

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








