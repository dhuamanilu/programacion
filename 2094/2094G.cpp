//#pragma GCC optimize ("Ofast")
//? #pragma GCC target ("avx,avx2")
//#pragma GCC optimize ("trapv")
//#undef _GLIBCXX_DEBUG //? for Stress Testing
#include <bits/stdc++.h>
using namespace std;

//* Debugger
string to_string(string s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(char c) {
    return string(1, c);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

template <typename A>
string to_string(A v);

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "[";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "]";
    return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define MACRO(code) do {code} while (false)
#define dbg(x)      {auto xd = x; cout << "Line(" << __LINE__ << "): " << "\033[1;34m" << #x << "\033[0;32m = \033[35m" << to_string(xd) << "\033[0m" << endl;}
#define dbg(...)    MACRO(cout << "Line(" << __LINE__ << "): " << "\033[1;34m" << "[" << #__VA_ARGS__ << "]\033[35m:"; debug_out(__VA_ARGS__); cout << "\033[0m";)

#define GA          dbg(0)
#define RAYA        cout << "\033[101m" << "================================" << "\033[0m" << endl;
#else
#define dbg(x)
#define dbg(...)
#define GA
#define RAYA
#endif
//* /Debugger

using ll = long long;
using db = long double; // or double if tight TL
using str = string;

using pi = pair<int,int>;
using pl = pair<ll, ll>;
#define mp make_pair
#define f first
#define s second

#define tcT template<class T
tcT> using V = vector<T>;
tcT, size_t SZ> using AR = array<T,SZ>;
using vi = V<int>;
using vl = V<ll>;
using vb = V<bool>;
using vpi = V<pi>;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsz resize
#define pb push_back
#define ft front()
#define bk back()

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

const int MOD = 1e9+7;
const db PI = acos((db)-1);
mt19937 rng(0); // or mt19937_64
//* mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; } // set a = max(a,b)

void setIn(string s) { freopen(s.c_str(), "r", stdin); }
//? /Custom Helpers
//? Generator
int rng_int(int L, int R) { assert(L <= R);
	return uniform_int_distribution<int>(L,R)(rng);  }
ll rng_ll(ll L, ll R) { assert(L <= R);
	return uniform_int_distribution<ll>(L,R)(rng);  }
struct Node{
    ll val;
    Node* next;
    Node* prev;
};
vl brute(V<pl> &ops){
    ll q = ops.size();
    
    
    auto calc = [](vl &a){
        ll n = a.size() , ans = 0;
        for(ll i = 0; i < n; i++){
            ans += (i + 1) * a[i];
        }
        return ans;
    };
    vl res;
    vl arr;
    for(ll i = 0; i < q; i++){
        auto [type , value] = ops[i];
        if(type == 1){
            vl nuevo;
            nuevo.push_back(arr.back());
            arr.pop_back();
            nuevo.insert(nuevo.end(),all(arr));
            arr = nuevo;
        }
        else if(type == 2){
            reverse(all(arr));
        }
        else{
            assert(type == 3);
            arr.push_back(value);
        }
        res.push_back(calc(arr));
    }
    return res;
}
vl solve(V<pl> &ops){
    ll q = ops.size();
    ll sumPref = 0 , sumSuff = 0 , dir = 0 , tam = 0 , sumi = 0;
    Node* actual = nullptr;
    //direccion 0 es -- , direccion 1 es ++ 
    vl ans;
    auto printList = [&](){
        Node* guarda = actual;
        Node* guarda2 = actual;
        RAYA;
        do{
            dbg(guarda->val);
            guarda = guarda -> next;
        }while(guarda != guarda2);
        RAYA;
    };
    for(ll i = 0; i < q; i++){
        ll type = ops[i].first;
        if(actual != nullptr) printList();
        //if(actual != nullptr) dbg("este es mi actual ", i , actual->val ,actual->prev->val , actual->next->val);
        if(type == 1){
            //Perform a cyclic shift on the array
            ll value = actual->val;
            dbg(sumi , tam ,sumSuff);
            sumSuff += (sumi - value) - ((tam - 1) * value);
            sumPref += (-1ll * (sumi - value)) + ((tam - 1) * value);
            /*if(dir == 0) actual = actual->prev;
            else actual = actual->next;*/
            actual = actual->prev;
        }
        else if(type == 2){
            //Reverse the entire array. 
            swap(sumPref,sumSuff);
            /*if(dir == 0) actual = actual->next;
            else actual = actual->prev;*/
            actual = actual->next;
            //dir ^= 1;
        }
        else{
            assert(type == 3);
            //Append an element to the end of the array. 
            ll ele = ops[i].second;
            tam++;
            
            sumSuff += tam * ele;
            sumi += ele;
            sumPref += sumi;
            if(actual == nullptr){
                Node* nuevo = new Node;
                nuevo->val = ele;
                nuevo->next = nuevo;
                nuevo->prev = nuevo;
                //dbg("ctmr11111",nuevo->val , nuevo->next->val , nuevo->prev->val);
                actual = nuevo;
                //dbg(actual->val , actual->next->val , actual->prev->val);
            }
            else{
                Node* nuevo= new Node;
                nuevo->val = ele;

                nuevo->next = actual->next;
                nuevo->prev = actual;

                //recien preparando
                dbg("ctmr",nuevo->val , nuevo->next->val , nuevo->prev->val);
                Node* guardaNext = actual->next;
                dbg(guardaNext->val);
                actual->next = nuevo;
                guardaNext->prev = nuevo;

                actual = nuevo;
                //dbg(actual->val , actual->next->val , actual->prev->val);
            }
        }
        ans.push_back(sumSuff);
    }
    return ans;
    
    
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    while(1){
        ll q = rng_ll(1,7);
        V<pl> ops(q);
        ops[0].first = 3;
        ops[0].second = rng_ll(1,10);
        for(ll i = 1 ;i < q; i++){
            ops[i].first = rng_ll(1 , 3);
            if(ops[i].first == 3){
                ops[i].second = rng_ll(1,10);
            }
        }
        auto ans1 = brute(ops);
        auto ans2 = solve(ops);
        if(ans1!=ans2){
            dbg("xd" , ops , ans1 , ans2);
            assert(false);
        }
        else dbg("ok");
    }
    cin>>t;
    while(t--){
        ll q;
        cin>>q;
        V<pl> ops(q);
        for(ll i = 0; i < q; i++){
            cin>>ops[i].first;
            if(ops[i].first == 3){
                cin>>ops[i].second;
            }
        }
        auto ans = solve(ops);
        for(auto & e : ans){
            cout<<e<<"\n";
        }
    }
}