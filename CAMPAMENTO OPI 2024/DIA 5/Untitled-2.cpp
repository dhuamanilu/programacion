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
#ifdef LOCAL
	#define n_l '\n'
	#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; cout << to_string(__VA_ARGS__) << endl
	template <typename T, size_t N> int SIZE(const T (&t)[N]){ return N; } template<typename T> int SIZE(const T &t){ return t.size(); } string to_string(const string s, int x1=0, int x2=1e9){ return '"' + ((x1 < s.size()) ? s.substr(x1, x2-x1+1) : "") + '"'; } string to_string(const char* s) { return to_string((string) s); } string to_string(const bool b) { return (b ? "true" : "false"); } string to_string(const char c){ return string({c}); } template<size_t N> string to_string(const bitset<N> &b, int x1=0, int x2=1e9){ string t = ""; for(int __iii__ = min(x1,SIZE(b)),  __jjj__ = min(x2, SIZE(b)-1); __iii__ <= __jjj__; ++__iii__){ t += b[__iii__] + '0'; } return '"' + t + '"'; } template <typename A, typename... C> string to_string(const A (&v), int x1=0, int x2=1e9, C... coords); int l_v_l_v_l = 0, t_a_b_s = 0; template <typename A, typename B> string to_string(const pair<A, B> &p) { l_v_l_v_l++; string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; l_v_l_v_l--; return res; } template <typename A, typename... C> string to_string(const A (&v), int x1, int x2, C... coords) { int rnk = rank<A>::value; string tab(t_a_b_s, ' '); string res = ""; bool first = true; if(l_v_l_v_l == 0) res += n_l; res += tab + "["; x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v)); auto l = begin(v); advance(l, x1); auto r = l; advance(r, (x2-x1) + (x2 < SIZE(v))); for (auto e = l; e != r; e = next(e)) { if (!first) { res += ", "; } first = false; l_v_l_v_l++; if(e != l){ if(rnk > 1) { res += n_l; t_a_b_s = l_v_l_v_l; }; } else{ t_a_b_s = 0; } res += to_string(*e, coords...); l_v_l_v_l--; } res += "]"; if(l_v_l_v_l == 0) res += n_l; return res; } void dbgm(){;} template<typename Heads, typename... Tails> void dbgm(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgm(T...); }
	#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgm(__VA_ARGS__); cout << endl
#else
	#define dbg(...)
	#define dbgm(...)
#endif
const int BASE = 1000000000;

struct bigint {
  vector<int> v;

  int size() const {
    return v.size();
  }

  int operator[](int x) const {
    if (x >= (int)v.size()) return 0;
    return v[x];
  }
};

bigint operator+(const bigint& a, const bigint& b) {
  bigint res;
  int c = 0;
  for (int i = 0; i < a.size() || i < b.size() || c; i++) {
    c += a[i] + b[i];
    res.v.push_back(c % BASE);
    c /= BASE;
  }
  return res;
}

bigint operator*(const bigint& a, int b) {
  bigint res;
  ll c = 0;
  for (int i = 0; i < a.size()  || c; i++) {
    c += a[i] * 1LL * b;
    res.v.push_back(c % BASE);
    c /= BASE;
  }
  return res;
}

bool operator<(const bigint& a, const bigint& b) {
  for (int i = max(a.size(), b.size()) - 1; i >= 0; i--) {
    if (a[i] != b[i]) {
      return a[i] < b[i];
    }
  }
  return false;
}
ll cont=0;
ll calc1(ll m){
	ll a=m*(m+1)/2;
	return a*a-9;
}
ll get1(ll &pos){
	ll guarda=-1;
	for(ll m=2079;m>=3;m--){
		ll r=calc1(m);
		ll l=r+1-m*m*m;
		if(pos>= l && pos<=r){
			guarda=m;
			//pos-=l;
			break;
		}
	}
	return guarda;
}
ll calc2(ll n,ll a){
	return a*n*n;
}
ll get2(ll &pos,ll n){
	pos-=calc1(n-1);
	ll guarda=-1;
	for(ll a=n;a>=1;a--){
		ll r=calc2(n,a);
		ll l=r+1-n*n;
		//dbgm(pos,l,r);
		if(pos>=l && pos<=r){
			guarda=a;
			break;
		}
	}
	return guarda;
}
ll calc3(ll n,ll b){
	return b*n;
}
ll get3(ll &pos,ll n,ll a){
	pos-=calc2(n,a-1);
	//dbg(pos);
	ll guarda=-1;
	for(ll b=n;b>=1;b--){
		ll r=calc3(b,n);
		ll l=r+1-n;
		//dbgm(pos,l,r,b);
		if(pos>=l && pos<=r){
			guarda=b;
			//pos-=l;
			break;
		}
	}
	return guarda;
}
ll get4(ll &pos,ll n,ll a,ll b){
	pos-=calc3(n,b-1);
	return pos;
}
ll LL,RR,len;
bigint binpow(ll a,ll b) {
    if (b == 0){
    	bigint aux;
    	aux.v.pb(1);
    	return aux;
    }
    bigint res = binpow(a, b / 2);
    if (b%2)
        return res * res * a;
    else
        return res * res;
}
void go(ll a,ll b,ll c,ll n){
	if(cont==len) return;
	cont++;
	//como comparo :v
	bigint pri=binpow(a,n),seg=binpow(b,n),
	ter=binpow(c,n);
	char comp=(pri + seg > ter ? '>':'<');	
	cout<<a<<"^"<<n<<"+"<<b<<"^"<<n<<comp
	<<c<<"^"<<n<<"\n";
	if(c+1<=n){
		go(a,b,c+1,n);
	}
	else{
		if(b+1<=n){
			go(a,b+1,1,n);
		}
		else{
			if(a+1<=n){
				go(a+1,1,1,n);
			}
			else{
				go(1,1,1,n+1);
			}
		}
	}
}
void solve(){
    cin>>LL>>RR;
    len=RR-LL+1;
    //n o maxi
    ll n=get1(LL);
    ll a=get2(LL,n);
    ll b=get3(LL,n,a);
    ll c=get4(LL,n,a,b);
    //dbgm(a,b,c,n);
    go(a,b,c,n);
    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}








