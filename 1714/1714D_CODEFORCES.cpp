#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


typedef pair<int, int> pi;

typedef vector<int> vi;
typedef vector<ll> vll;
#define FOR(i, a, b) for (long long i=a; i<(b); i++)

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
bool ok=true;
void Find(int n,int m,string &t, vector<string> &a, vector<pair<ll,ll>> &mat){
    for(int i=n;i<m;i++){
        //NEGAI


    }
}
void solve(){
    string t;
    cin>>t;
    int n;
    cin>>n;
    vector <string> a(n);
    FOR(i,0,n){
        cin>>a[i];
    }
    vector<pair<ll,ll>> match;

    Find(0,0,t,a,match);

    if(!ok){
        cout<<"-1\n";
        return;
    }
    else{
        for(auto a : match){
            cout<<a.first<<" "<<a.second<<"\n";
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    /*if (fopen("abcd.in", "r")) {
		freopen("billboard.in", "r", stdin);
		freopen("billboard.out", "w", stdout);
    }*/
  	int t=1;
    cin>>t;

  	while(t--){
        solve();
  	}
	return 0;
}
/*
void solve() {
	string t;
	cin >> t;
	int n;
	cin >> n;
	vector<string> s(n);
	for (auto &ele : s) cin >> ele;
	vector<pair<int, int>> ans;
	int l = -1, r = 0;
	for (int i = 0; i < t.size(); i++) {
		int tempr = (-1), templ, ind;
		for (int j = l + 1; j <= r; j++) {
			for (int k = 0; k < n; k++) {
				if (t.substr(j, s[k].size()) == s[k]) {
					if (tempr < (int)(j + s[k].size())) {
						tempr = (j + s[k].size());
						templ = j;
						ind = k;
					}
				}
			}
		}
		if (tempr == (-1)) {
			cout << -1 << endl;
			return;
		} else {
			ans.push_back({ind + 1, templ + 1});
			r = i = tempr;
			i--;
			l = templ;
		}
	}
	cout << ans.size() << endl;
	for (auto &ele : ans) {
		cout << ele.first << " " << ele.second << endl;
	}
}
*/







