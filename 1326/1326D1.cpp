#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
const int MOD2=998244353;
const char nl = '\n';
const int MX = 100001;
const int N=1000+3;
bool isPalindrome(string &S){
    string P = S;
    reverse(P.begin(), P.end());
    if (S == P) return true;
    else    return false;
}
void solve(){
    string s;
    cin>>s;
    ll n=s.size();
    map<string,ll> pref,suff;
    string aux="";
    FOR(i,0,n){
        aux+=s[i];
        pref[aux]++;
    }
    pref[""]++;
    suff[""]++;
    aux="";
    string copia=s;
    FOR(i,0,n){
        suff[copia]++;
        copia=copia.substr(1);
    }
    ll maxi=LONG_LONG_MIN;

    string ans;
    for(auto &e : pref){
        for(auto & e2 : suff){
            //cout<<"mi pref y suff: "<<e.f<<" "<<e2.f<<"\n";
            string aux=e.f+e2.f;
            if(aux.size()>s.size()) continue;
            if(isPalindrome(aux) ){
                if(aux.size()>maxi){
                    maxi=aux.size();
                    ans=aux;
                }
            }
        }
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








