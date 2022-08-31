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
    string s;
    cin>>s;
    vector <ll> a(27,0);
    FOR(i,0,s.length()){
        a[s[i]-'a']++;
    }
    ll i=0,j=s.length()-1;
    while(i<s.length() && j>=0){
        if(a[s[i]-'a']>=1){

            a[s[i]-'a']--;
            if(a[s[i]-'a'] == 0 ){
                FOR(k,0,27){
                    if(a[k]>=2){
                        cout<<"NO\n";
                        return;
                    }
                }
            }
            i++;
        }
        else if(a[s[j]-'a']>=1){

            a[s[j]-'a']--;
            if(a[s[j]-'a'] == 0 ){
                FOR(k,0,27){
                    if(a[k]>=2){
                        cout<<"NO\n";
                        return;
                    }
                }
            }
            j--;
        }
        if(a[s[i]-'a'] == 0 || a[s[j-'a']]==0){
            FOR(k,0,27){
                if(a[k]>=2){
                    cout<<"NO\n";
                    return;
                }
            }
        }
        if(i==j) break;
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








