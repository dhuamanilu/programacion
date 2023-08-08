#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map <ll,ll> mll;
typedef vector <pair<ll,ll>> vpll;
typedef priority_queue<ll> pq;
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
#define n_l '\n'
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; cout << to_string(__VA_ARGS__) << endl
#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgm(__VA_ARGS__); cout << endl
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;
const int N=1000+3;
ll bb(vll & a , ll t){
	ll s=0,e=(ll)1e18,m=s+(e-s)/2,ans=0;
	while(s<=e){
		m=s+(e-s)/2;
		ll tot=0;
        FOR(i,0,a.size()){
            tot+=m/a[i];
            if(tot>=t) break;
        }
        if(tot < t){
            s=m+1;
        }
        else{
            //dbg(ans);
            ans=m;
            e=m-1;
        }
	}
    return ans;

}
int main(){
	ll n,t;
	cin>>n>>t;
	vll a(n);
	FOR(i,0,n){
		cin>>a[i];
	}
	cout<<bb(a,t)<<"\n";
}








