#include <bits/stdc++.h>
using namespace std;
string to_string (string s){
    return '"' + s + '"';
}
string to_string(const char*s){
    return to_string((string) s);
}
string to_string(char c){
    return string(1,c);
}
string to_string(bool b){
    return b ? "true" : "false";
}
template <typename A>
string to_string(A v);
template <typename A , typename B>
string to_string(pair<A,B> p){
    return "(" + to_string(p.first) + " , " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v){
    bool first=true;
    string res="[";
    for(const auto & x : v){
        if(!first) res +=", ";
        first=false;
        res+=to_string(x);
    }
    res+="]";
    return res;
}
void debug_out(){
    cerr<<endl;
}
template <typename Head,typename...Tail>
void debug_out(Head H,Tail... T){
    cerr<<" "<<to_string(H);
    debug_out(T...);
}
#ifdef LOCAL
#define MACRO(code) do{code}while(false)
#define dbg(x){auto xd = x; cout<<"Line (:"<<__LINE__<<"):"<<"\033[1;34m"<<#x<<"\033[0;32m = \033[35m"<<to_string(xd)<<"\033[0m"<<endl;}
#define dbg(...) MACRO(cout<<"Line(" <<__LINE__<<"): "<<"\033[1;34m" <<"[" <<#__VA_ARGS__<<"]\033[35m:"; debug_out(__VA_ARGS__); cout<<"\033[0m";)

#define GA dbg(0)
#define RAYA cout<<"\033[101m"<<"=============="<<"\033[0m"<<end;
#else
#define dbg(x)
#define dbg(...)
#define GA
#define RAYA
#endif
using ll = long long;
using db = long double;
using str = string;
using pi = pair<int,int>;
using pl = pair<ll,ll>;
#define mp make_pair
#define f first
#define s second

#define tcT template <class T
tcT> using V = vector<T>;
tcT, size_t SZ> using AR = array<T,SZ>;
using vi = V<int>;
using vl = V<ll>;
using vb = V<bool>;
using vpi = V<pi>;

#define sz(x) int((x).size())
#define all(x) begin(x) , end(x)
#define sor(x) sort(all(x))
#define rsz resize
#define pb push_back
#define ft front()
#define bk back()

#define FOR(i,a,b) for(int i = (a) ; i < (b) ; ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for(int i = (b)-1;i>=(a);--i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for(auto & a : x)

const int MOD = 1e9 + 7;
const db PI = acos((db)-1);
//mt19937 rng(0);
mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
tcT> bool ckmin(T&a, const T&b){
    return b < a ? a=b,1:0;
}
tcT> bool ckmax(T&a, const T&b){
    return a < b ? a=b,1:0;
}
int rng_int(int L,int R){assert(L<=R);
return uniform_int_distribution<int>(L,R)(rng);}
ll rng_ll(ll L,ll R){assert(L<=R);
return uniform_int_distribution<ll>(L,R)(rng);}

const ll INF = 1e18;

tcT> struct SegTree{
    T ID{}; T cmb(T a, T b){
        return a+b;
    }
    int n;
    V<T> seg;
    void init(int _n){
        for(n=1;n < _n;) n*=2;
        seg.assign(2*n,ID);
    }
    void pull(int p){
        seg[p] = cmb(seg[2*p],seg[2*p+1]);
    }
    void upd(int p , T val){
        dbg(p);
        seg[p+=n] = val; for(p/=2;p;p/=2) pull(p);
    }
    T query(int l,int r){
        T ra = ID , rb = ID;
        for(l+=n,r+=n+1;l<r;l/=2 , r/=2){
            if(l&1) ra = cmb(ra,seg[l++]);
            if(r&1) rb = cmb(seg[--r],rb);
        }
        return cmb(ra,rb);
    }
};

struct node {
    ll val;
    ll pos;

    node() {
        val = -INF;
        pos = INF;
    }

    node(ll _val, ll _pos) : val(_val), pos(_pos) {}

    node operator+(const node& rhs) const {
        node res;
        if (rhs.val == val) {
            res.val = rhs.val;
            res.pos = min(rhs.pos, pos);
            return res;
        }

        if (rhs.val > val) res = rhs;
        else res = *this;

        return res;
    }
};

void solve() {
    ll n;
    cin >> n;

    vl a(n);
    for (ll i = 1; i < n; ++i) { cin >> a[i]; }

    V<vl> edges(n);
    for (ll i = 0; i < n-1; ++i) {
        ll u, v;
        cin >> u >> v; 
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    V<SegTree<node>> st(n);
    vl level(n);
    vl dep(n);

    {
        auto dfs = [&](auto&& self, ll p, ll u) -> void {
            ll res = 0;
            for (auto v : edges[u]) {
                if (v == p) continue;

                self(self, u, v);
                res = max(res, dep[v]+1);
            }
            dep[u] = res;
        };

        dfs(dfs, -1, 0);
    }

    dbg(dep);

    ll response = 0;
    ll time = INF;

    for (ll i = 0; i < n; ++i) {
            sort(all(edges[i]), [&](ll a, ll b) {
                if (dep[a] > dep[b]) return true;
                return false;
            });
    }

    dbg(a);
    auto dfs = [&](auto&& self, ll p, ll u, ll d) -> void {
        dbg("en", u);
        if (dep[u] == 0) {
            st[u].init(d+1);
            level[u] = d;
            st[u].upd(d, {a[u], d});
        } else {
            vl ve;
            for (auto v : edges[u]) {
                if (v == p) continue;
                ve.push_back(v);
            }

            ll k = sz(ve);

            self(self, u, ve[0], d);
            for (ll i = 1; i < k; ++i)  self(self, u, ve[i], dep[ve[i]]);

            ll fi = ve[0];
            swap(st[u], st[fi]);
            swap(level[u], level[fi]);
            level[u]--;
            st[u].upd(level[u], {a[u], level[u]});

            for (ll i = 1; i < k; ++i) {
                ll v = ve[i];
                for (ll d = 0; d <= dep[v]; ++d) {
                    node aux = st[v].query(level[v]+d, level[v]+d);
                    node aux2 = st[u].query(level[u]+d+1, level[u]+d+1);

                    st[u].upd(level[u]+d+1, {aux.val+aux2.val, level[u]+d+1});
                }
            }
        }

        // dbg("de u", u); 
        // for (ll i = 0; i <= dep[u]; ++i) {
        //     cout << st[u].query(level[u]+i, level[u]+i).val << " ";
        // }
        // cout << endl;
        // for (ll i = 0; i <= dep[u]; ++i) {
        //     cout << st[u].query(level[u]+i, level[u]+i).pos - level[u] << " ";
        // }
        // cout << endl;
        // dbg("de u", u); 

        if (u == 0) { return; }

        node wb = st[u].query(level[u], level[u]+dep[u]);
        wb.pos -= level[u];
        dbg(u, wb.val, wb.pos);

        if (wb.val > response) {
            response = wb.val;
            time = wb.pos;
        } else if (wb.val == response) {
            time = min(time, wb.pos);
        }

        dbg("sa", u);
    };

    dfs(dfs, -1, 0, dep[0]);

    cout << response << " " << time+1 << "\n";
}


void setIn(string s){
    freopen(s.c_str(),"r",stdin);
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    // setIn("input.txt");
    ll t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}