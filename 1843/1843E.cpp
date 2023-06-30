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
//https://leetcode.com/problems/range-sum-query-mutable/solutions/1218358/c-segment-tree-explained/
class NumArray {
public:
    vector<int> seg;
    int n;
    void buildTree(vector<int>& nums, int pos, int left, int right){
        if (left == right){
            seg[pos] = nums[left];
            return;
        }
        int mid = (left+right)/2;
        buildTree(nums, 2*pos+1, left, mid);
        buildTree(nums, 2*pos+2, mid+1, right);
        seg[pos]=seg[2*pos+1]+ seg[2*pos+2];
    }
    void updateUtil(int pos, int left, int right, int index, int val) {
        if(index <left || index >right) return;
        if(left==right){
            if(left==index)
                seg[pos]=val;
            return;
        }
        int mid=(left+right)/2;
        updateUtil(2*pos+1,left,mid,index,val);
        updateUtil(2*pos+2,mid+1,right,index,val);
        seg[pos]=seg[2*pos+1]+seg[2*pos+2];
    }
    int rangeUtil(int qlow, int qhigh, int low, int high, int pos){
        if (qlow <= low && qhigh>= high){
            return seg[pos];
        }
        if (qlow > high || qhigh < low) {
            return 0;
        }
        int mid = low+(high-low)/2;
        return (rangeUtil(qlow, qhigh, low, mid, 2*pos+1) + rangeUtil(qlow, qhigh, mid+1, high, 2*pos+2));
    }
    NumArray(vector<int>& nums) {
        if(nums.size() > 0){
            n = nums.size();
            seg.resize(4*n,0);
            buildTree(nums, 0, 0, n-1);
        }
    }
    void update(int index, int val) {
        if(n==0)return;
        updateUtil(0,0,n-1, index, val);
    }
    int sumRange(int left, int right) {
        if(n==0)return 0;
        return rangeUtil(left, right, 0, n-1, 0);
    }
};
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>> a(m,{0,0});
    FOR(i,0,m){
        cin>>a[i].f>>a[i].se;
        a[i].f--;
        a[i].se--;
    }
    //obj->update(index,val);
    //int param_2 = obj->sumRange(left,right);
    ll q;
    cin>>q;
    vll cambios(q);
    FOR(i,0,q){
        cin>>cambios[i];
        cambios[i]--;
    }
    ll ans=-1,s=0,e=q,mid=s+(e-s)/2;

    while(s<=e){
        vector<int> nums(n,0);
        NumArray* obj = new NumArray(nums);
        mid=s+(e-s)/2;
        bool ok=false;
        FOR(j,0,mid){
            obj->update(cambios[j],1);
        }
        for(auto & e : a){
            if(2*obj->sumRange(e.f,e.se) > e.se-e.f+1){
                ok=true;
                break;
            }
        }
        if(ok){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
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








