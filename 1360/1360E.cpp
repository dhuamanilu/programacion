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
    ll n;
    cin>>n;
    ll a[n][n];
    FOR(i,0,n){
        string s;
        cin>>s;
        FOR(j,0,n){
            a[i][j]=s[j]-'0';
        }
    }
    /*FOR(i,0,n){
        FOR(j,0,n){
            cout<<a[i][j];
        }
        cout<<"\n";
    }*/
    FOR(i,0,n){
        FOR(j,0,n){
            if(a[i][j]==1){
                //if(i==0){
                    bool ok=true,ok2=true;
                    if(i+1<n){
                        if(a[i+1][j]==0){
                            ok=false;
                        }
                    }
                    if(j+1<n){
                        if(a[i][j+1]==0){
                            ok2=false;
                        }
                    }
                    if(!ok && !ok2){
                        cout<<"NO\n";
                        return;
                    }
                //}
                /*else{
                    bool ok1=true,ok2=true;
                    FOR(k,j+1,n){
                        if(a[i][k]!=1){
                            ok1=false;
                            break;
                        }
                    }
                    for(ll k=i-1;k>=0;k--){
                        if(a[k][j]!=1){
                            ok2=false;
                            break;
                        }
                    }
                    if(!ok1 && !ok2){
                        cout<<"NO\n";
                        return;
                    }
                }*/

            }
        }
    }
    cout<<"YES\n";

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  	int t=1;
    cin>>t;
  	while(t--){
        solve();
  	}
	return 0;
}
