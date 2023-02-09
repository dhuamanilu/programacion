#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map <ll,ll> mll;
typedef vector <pair<ll,ll>> vpll;
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
    string s;
    cin>>s;
    if(s[0]=='N'){
        ll n;
        cin>>n;
        //cout<<"ESTE ES EL NUMBER :"<<n<<"\n";
        string aux(4,'0');
        vector<string> ans(5,aux);
        ll val[]={5,3,2,1};
        ll mult[]={10000,1000,100,10,1};
        FOR(i,0,5){
            FOR(j,0,4){
                if(val[j]*mult[i]>n){
                    continue;
                }
                n-=val[j]*mult[i];
                ans[i][j]='1';
            }
        }
        for(auto e : ans){
            cout<<e<<"\n";
        }
    }
    else{
        ll a,b;
        cin>>a>>b;
        string aux(4,'0');
        vector<string> ans(5,aux);
        ll val[]={5,3,2,1};
        ll mult[]={10000,1000,100,10,1};
        FOR(i,0,5){
            FOR(j,0,4){
                if(val[j]*mult[i]>a){
                    continue;
                }
                a-=val[j]*mult[i];
                ans[i][j]++;
            }
        }
        FOR(i,0,5){
            FOR(j,0,4){
                if(val[j]*mult[i]>b){
                    continue;
                }
                b-=val[j]*mult[i];
                ans[i][j]++;
            }
        }
        vector <string> res;
        FOR(i,0,5){
            FOR(j,0,4){
                if(ans[i][j]=='2'){
                    if(j==0){
                        ans[i-1][j+3]++;
                    }
                    else if(j==1){
                        ans[i][j-1]++;
                        ans[i][j+2]++;
                    }
                    else if(j==2){
                        ans[i][j-1]++;
                        ans[i][j+1]++;
                    }
                    else{
                        ans[i][j-1]++;
                    }
                    string ope="D "+to_string(val[j])+", "+to_string(mult[i]);
                    res.pb(ope);
                    ans[i][j]='0';
                }
            }
        }
        FOR(i,0,5){
            FOR(j,1,4){
                if(j+1<4 && ans[i][j]=='1' && ans[i][j+1]=='1'){
                    string ope="S "+to_string(val[j+1])+", "+to_string(mult[i]);
                    res.pb(ope);
                    ans[i][j-1]++;
                    ans[i][j]--;
                    ans[i][j+1]--;
                }
            }
        }
        sort(all(res));
        for(auto e : res){
            cout<<e<<"\n";
        }
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








