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
    string s="";
    FOR(i,0,n){
        s+="BAN";
    }
    ll cont=0,j=3*n-1;
    vector <pair<ll,ll>> vec;
    FOR(i,0,3*n){
        bool ok=true;
        FOR(k,0,3*n){
            if(s[k]=='B'){
                ll ind=k+1,contA=0,contN=0;
                while(ind<3*n){
                    if(s[ind]=='A') contA++;
                    else if(s[ind]=='N') contN++;
                    if(contA>0 && contN>0){
                        ok=false;
                        break;
                    }
                    ind++;
                }
                if(!ok) break;
            }
        }
        if(ok) break;

        if(s[i]=='B'){
            cont++;
            while(s[j]=='B' && j>0){
                j--;
            }
            vec.push_back(mp(i,j));
            swap(s[i],s[j]);
        }
    }
    cout<<vec.size()<<"\n";
    FOR(i,0,vec.size()){
        cout<<vec[i].first+1<<" "<<vec[i].second+1<<"\n";
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
