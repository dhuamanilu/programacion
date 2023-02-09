#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
template <typename T, size_t N> int SIZE(const T (&t)[N]){ return N; } template<typename T> int SIZE(const T &t){ return t.size(); } string to_string(const string s, int x1=0, int x2=1e9){ return '"' + ((x1 < s.size()) ? s.substr(x1, x2-x1+1) : "") + '"'; } string to_string(const char* s) { return to_string((string) s); } string to_string(const bool b) { return (b ? "true" : "false"); } string to_string(const char c){ return string({c}); } template<size_t N> string to_string(const bitset<N> &b, int x1=0, int x2=1e9){ string t = ""; for(int __iii__ = min(x1,SIZE(b)),  __jjj__ = min(x2, SIZE(b)-1); __iii__ <= __jjj__; ++__iii__){ t += b[__iii__] + '0'; } return '"' + t + '"'; } template <typename A, typename... C> string to_string(const A (&v), int x1=0, int x2=1e9, C... coords); int l_v_l_v_l = 0, t_a_b_s = 0; template <typename A, typename B> string to_string(const pair<A, B> &p) { l_v_l_v_l++; string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; l_v_l_v_l--; return res; } template <typename A, typename... C> string to_string(const A (&v), int x1, int x2, C... coords) { int rnk = rank<A>::value; string tab(t_a_b_s, ' '); string res = ""; bool first = true; if(l_v_l_v_l == 0) res += n_l; res += tab + "["; x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v)); auto l = begin(v); advance(l, x1); auto r = l; advance(r, (x2-x1) + (x2 < SIZE(v))); for (auto e = l; e != r; e = next(e)) { if (!first) { res += ", "; } first = false; l_v_l_v_l++; if(e != l){ if(rnk > 1) { res += n_l; t_a_b_s = l_v_l_v_l; }; } else{ t_a_b_s = 0; } res += to_string(*e, coords...); l_v_l_v_l--; } res += "]"; if(l_v_l_v_l == 0) res += n_l; return res; } void dbgm(){;} template<typename Heads, typename... Tails> void dbgm(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgm(T...); }
#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgm(__VA_ARGS__); cout << endl
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;
const int N=1000+3;
template<class T>
struct segment_tree{
    int n;
    vector<T> tree;
    segment_tree(int n){
        this->n=n;
        tree.resize(2*n);
    }
    segment_tree(vector<T> values){
        this->n =values.size();
        tree.resize(2*n);
        for(int i=0;i<n;i++){
            upd(i,values[i]);
        }
    }
    T compare(T a,T b){
        return a+b;
    }
    void modify(int index,T value){
        index+=n;
        tree[index]=value;
        for(index>>=1;index>=1;index>>=1){
            tree[index]=compare(tree[index*2],tree[index*2+1]);
        }
    }
    void upd(int index,T value){
        index+=n;
        tree[index]=compare(tree[index],value);
        for(index>>=1;index>=1;index>>=1){
            tree[index]=compare(tree[index*2],tree[index*2+1]);
        }
    }
    T query(int first,int last){
        first+=n,last+=n;
        T ans=0;
        while(first<=last){
            if(first%2==1){
                ans=compare(ans,tree[first++]);
            }
            if(last%2==0){
                ans=compare(ans,tree[last--]);
            }
            first>>=1;
            last>>=1;
        }
        return ans;
    }

};
ll getSum(ll n){
    ll sum=0;
    while(n!=0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
void solve(){
    ll n,q;
    cin>>n>>q;
    vector<vll> a(n);
    segment_tree<int> st(n+1);
    FOR(i,0,n){
        ll x;
        cin>>x;
        a[i].pb(x);
        while(x>9){
            x=getSum(x);
            a[i].pb(x);
        }
    }
    FOR(i,0,q){
        ll num;
        cin>>num;
        dbg(st.tree);
        if(num==1){
            ll l,r;
            cin>>l>>r;
            l--;
            st.upd(l,1);
            if(r!=n)
                st.upd(r,-1);
        }
        else{
            ll ind;
            cin>>ind;
            ind--;
            ll pos=st.query(0,ind);
            if(a[ind].size()-1 < pos){
                pos=a[ind].size()-1 ;
            }
            cout<<a[ind][pos]<<"\n";
        }
    }
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








