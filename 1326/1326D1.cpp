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
string prefix_function(const string& s) {
    string aux=s;
    reverse(all(aux));
    aux=s+"#"+aux;
    ll n=(ll)aux.size();
    vector<ll> pi(n);
    pi[0]=0;
    ll j;
    FOR(i,1,n){
        j=pi[i-1];
        while(j>0 && aux[i]!=aux[j]){
            j=pi[j-1];
        }
        if(aux[i]==aux[j]){
            j++;
        }
        pi[i]=j;
    }
    return s.substr(0,j);
}
void solve(){
    string s;
    cin>>s;
    ll n=(ll)s.size();
    ll k=0;
    while(2*k+1<n && s[k]==s[n-1-k]){
        k++;
    }
    if(k>0){
        cout<<s.substr(0,k);
    }
    if(n>2*k){
        string med=s.substr(k,n-2*k);
        string pre1=prefix_function(med);
        reverse(all(med));
        string pre2=prefix_function(med);
        if ((int)pre1.size()<(int)pre2.size())
            swap(pre1, pre2);
        cout<<pre1;
    }
    if(k>0){
        cout<<s.substr(n-k,k);
    }
    cout<<"\n";
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








