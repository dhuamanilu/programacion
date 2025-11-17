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

V<pl> brute(vl &a){
    ll n = a.size();
    set<array<ll,3>> closests;
    for(ll row = 0; row < n; row++){
        for(ll col = 0; col <= row; col++){
            array<ll,3> aaa = {1 + (4 * row) , 1 + (3 * col) , 1 + (3 * row) - (3 * col)};
            auto [dist, x , y] = aaa;
            closests.insert({dist , x , y });
            closests.insert({dist + 1 , x + 1 , y });
            closests.insert({dist + 1 , x , y + 1 });
            closests.insert({dist + 4 , x + 1 , y + 1});
        }
    }
    dbg(closests);
    ll row = 0 ,col = -1;
    V<pl> ans;
    for(auto & e : a){
        if(e == 1){
            auto ptr = closests.begin();
            array<ll,3> point = *ptr;
            closests.erase(ptr);
            auto [dist, x , y] = point;
            ans.push_back({x , y});
        }
        else{
            if(col + 1 > row){
                row++;
                col = 0;
            }
            else{
                col++;
            }
            array<ll,3> aaa = {1 + (4 * row), 1 + (3 * col) , 1 + (3 * row) - (3 * col)};
            auto encontrar = closests.lower_bound(aaa);
            assert(encontrar != closests.end() && *encontrar == aaa);
            auto [dist, x , y] = *encontrar;
            closests.erase(encontrar);
            ans.push_back({x , y});
        }
    }

    return ans;
}

V<pl> solve(vl &a) {
    
    ll n = a.size();
    // 1 al mas cercano , 0 que no este ocupada 
    ll row = 0 , col = -1;
    set<array<ll,3>> closests;
    auto obtenerPunto = [&](){
        auto ptr = closests.begin();
        array<ll,3> point = *ptr;
        closests.erase(ptr);
        return point;
    };
    set<array<ll,3>> pendings;
    auto insert = [&](){
        if(col + 1 > row){
            row++;
            col = 0;
        }
        else{
            col++;
        }
        array<ll,3> aaa = {1 + (4 * row), 1 + (3 * col) , 1 + (3 * row) - (3 * col)};
        auto [dist, x , y] = aaa;
        
        closests.insert({dist + 1 , x + 1 , y });
        closests.insert({dist + 1 , x , y + 1 });
        pendings.insert({dist + 4 , x + 1 , y + 1});
        return aaa;
    };
    V<pl> ans;
    for(auto & e : a){
        if(e == 1){
            auto poner = insert();
            closests.insert(poner);
            auto [dist , x , y] = obtenerPunto();
            dbg(dist , x ,y);
            



            ///////////////////
            auto ptrPorsiacaso = pendings.begin();
            auto [d2 ,x2 , y2] = *ptrPorsiacaso;
            dbg(d2 , x2 ,y2);
            if(d2 < dist || (d2 == dist && (x2 < x || (x2 == x && y2 < y)))){
                dbg("esta mal" , d2 < dist , d2 == dist);
                ans.push_back({x2 , y2});
                pendings.erase(ptrPorsiacaso);
                closests.insert({dist , x , y});
            }
            else{
                dbg("esto imprimire" ,dist , x, y);
                ans.push_back({x , y});
            }
            
            
        }
        else{
            auto [dist , x , y] = insert();
            dbg("e es 0 , tiene que ser nueva si o si ", dist, x ,y);
            ans.push_back({x , y});
        }
    }
    return ans;

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    //? Stress Testing
    while(0) {
        ll n =rng_ll(1 , 10);
        vl a(n);
        for(auto & e : a) e = rng_ll(0 , 1);
        auto ans1 = brute(a);
        auto ans2 = solve(a);
        if(ans1!=ans2){
            dbg(a,ans1,ans2);
            assert(false);
        }
        else dbg("ok");
    }

    int t = 1;
	cin >> t;
    for(int i = 0; i < t; i++) {
        ll n;
        cin>>n;
        vl a(n);
        for(auto & e : a)cin>>e;
        //dbg(brute(a));
        auto ans = solve(a);
        for(auto & [x,y] : ans){
            cout<<x<<" "<<y<<"\n";
        }
    }
    return 0;
}