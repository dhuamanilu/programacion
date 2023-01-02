#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<ll,ll>> vpll;
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
struct dsu {
	vector<int> p, s;
	dsu(int n) {
		p.resize(n);
		iota(p.begin(), p.end(), 0);
		s.resize(n, 1);
	}

	int get(int v) {
		return p[v] == v ? v : p[v] = get(p[v]);
	}

	int merge(int a, int b) {
		a = get(a);
		b = get(b);
		if (a != b) {
			if (s[a] > s[b])
				swap(a, b);
			s[b] += s[a];
			p[a] = b;
			return 1;
		}
		return 0;
	}
};
void solve(){
    int n,m1,m2;
    cin>>n>>m1>>m2;
    dsu M(n),D(n);
    FOR(i,0,m1){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        M.merge(u,v);
    }
    FOR(i,0,m2){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        D.merge(u,v);
    }
    vector <pair<int,int > > a;
    FOR(i,0,n){
        FOR(j,0,n){
            if(M.get(i)!=M.get(j) && D.get(i)!=D.get(j)){
                a.pb({i+1,j+1});
                M.merge(i,j);
                D.merge(i,j);
            }
        }
    }
    cout<<a.size()<<"\n";
    for(auto e : a){
        cout<<e.f<<" "<<e.se<<"\n";
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








