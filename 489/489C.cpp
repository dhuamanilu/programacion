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
    ll m,s;
    cin>>m>>s;
    if(m==1 && s==0){
        cout<<"0 0\n";
        return;
    }
    if(s==0 || m*9<s){
        cout<<"-1 -1\n";
        return;
    }
    string ans="";
    while(true){
        if(s>9){
            s-=9;
            ans+="9";
        }
        else{
            ans+=to_string(s);
            s=0;
            break;
        }
    }
    bool ok=false;
    while(ans.size()<m){
        ans+="0";
        ok=true;
    }
    if(ok){
        string ans2=ans;
        reverse(all(ans2));
        ll i=0,len=ans2.size(),pos=0;
        while(i<len && ans2[0]=='0'){
            if(ans2[i]!='0'){
                ans2[i]=char(ans2[i]-1);
                ans2[pos]='1';
                pos++;
            }
            i++;
        }
        cout<<ans2<<" "<<ans<<"\n";

    }
    else{
        string ans2=ans;
        reverse(all(ans));
        cout<<ans<<" "<<ans2<<"\n";
    }

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}








