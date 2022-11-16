#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
#define FOR(i, a, b) for (long long i=a; i<(b); i++)
#define FOR1(i, a, b) for (long long i=a; i<=(b); i++)
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
    string s;
    cin>>s;
    ll cont1=0,cont2=0;
    FOR(i,0,n){
        if(s[i]=='1'){
            cont1++;
        }
        else cont2++;
    }
    vector <vector <char> > res(n,vector<char>(n,'='));
    if(n*(n-1)/2 - (cont2)>=cont1){
        cout<<"YES\n";
        FOR(i,0,n){
            FOR(j,0,n){
                if(i==j){
                    res[i][j]='X';
                    continue;
                }

                if(s[i]=='2'){

                    while(s[j]=='1' ){
                        j++;
                    }

                    while(res[i][j]=='+' || res[i][j]=='-' ){
                        j++;
                    }

                    while(s[j]=='1' ){
                        j++;
                    }
                    j%=n;
                    res[i][j]='+';
                    res[j][i]='-';

                    s[i]='0';

                }
                FOR(i,0,n){
                        FOR(j,0,n){
                            cout<<res[i][j];
                        }
                        cout<<"\n";
                }
                    cout<<"nueva ineaaaaaaa\n";

            }
        }
        /*FOR(i,0,n){
            FOR(j,0,n){
                cout<<res[i][j];
            }
            cout<<"\n";
        }*/
    }
    else {
        cout<<"NO\n";
        return;
    }
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








