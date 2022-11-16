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
    vector <string> vec,vec2;
    vector <ll> cont1(11,0),cont2(11,0);
    FOR(i,0,n){
        string s;
        cin>>s;
        cont1[s[0]-'a']++;
        vec.push_back(s);
        reverse(s.begin(),s.end());
        string s2=s;
        cont2[s2[0]-'a']++;
        vec2.push_back(s2);
    }
    sort(all(vec));
    sort(all(vec2));
    ll ans=0;
    cout<<"CONTADORES DE CONT1\n";
    for(auto e : cont1){
        cout<<e<<" ";
    }
    cout<<"\n";
    FOR(i,0,n){
        ll contado=cont1[vec[i][0]-'a'];
        ll j=i+1;
        while(j<n && vec[i]==vec[j]){
            j++;
            contado--;
        }
        cout<<"aumentare ans en : "<<contado<<" "<<contado*(contado-1)/2<<"\n";
        ans+=contado*(contado-1)/2;
    }
    cout<<ans<<"\n";

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








