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
bool bb(vll & a , ll t){
	ll s=0,e=a.size(),m=s+(e-s)/2;
	while(s<=e){
		m=s+(e-s)/2;
		if(a[m]==t) return true;
		else if(a[m]<t){
			s=m+1;
		}
		else{
			e=m-1;
		}
	}
	return false;

}
int main(){
	ll n,q;
	cin>>n>>q;
	vll a(n);
	FOR(i,0,n){
		cin>>a[i];
	}
	FOR(i,0,q){
		ll x;
		cin>>x;
		if(bb(a,x)){
            cout<<"YES\n";
		}
		else{
            cout<<"NO\n";
		}
	}
}








