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

void solve(V<vl> &a){
    ll n = a.size();
    if(n==1){
        cout<<"YES\n";
        return;
    }
    bool ok = true;
    
    for(ll i = 0;i < n; i++){
        for(ll j = 0;j < n; j++){   
            if(a[i][j] == 0) continue;
            
            ll cont = 0;
            //horizontal ---
            if((j + 1) < n && (a[i][j+1] == 1)){
                cont++;
            }
            if((j + 2) < n && (a[i][j+2] == 1)){
                cont++;
                ok = false;
                break;
            }
            if(cont == 2){
                ok = false;
                break;
            }

            
            ll cont2 = 0;
            //horizontal ---
            if((i + 1) < n && (a[i+1][j] == 1)){
                cont2++;
            }
            if((i + 2) < n && (a[i+2][j] == 1)){
                cont2++;
                ok = false;
                break;
            }
            if(cont2 == 2){
                ok = false;
                break;
            }
            if(!ok) break;
        }
        if(!ok) break;
    }
    if(!ok){
        cout<<"NO\n";
        return;
    }
    vl dx = {1 , -1, 0, 0};
    vl dy = {0, 0, 1, -1};
    ll cuantos = 0;
    V<vl> vis(n,vl(n,0));
    auto isValid= [&](ll x,ll y){
        return x >= 0 && x < n && y >= 0 && y < n;
    };
    auto dfs=[&](auto &&dfs,ll x,ll y)->void{

        vis[x][y] = 1;
        cuantos++;
        for(ll k = 0;k < 4; k++){
            ll newX = x + dx[k] , newY = y + dy[k];
            if(isValid(newX,newY)){
                if(!vis[newX][newY] && a[newX][newY] == 1){
                    dfs(dfs,newX,newY);
                }
            }
        }
    };

    set<pl> negros;
    for(ll i= 0;i < n;i++){
        for(ll j = 0; j < n; j++){
            if(a[i][j] == 1){
                negros.insert(make_pair(i,j));
            }
        }
    }
    pl primero = { -1, -1 },segundo = { -1 , -1 };
    bool found = false;
    for(ll i = 0;i < n; i++){
        for(ll j = 0;j < n; j++){
            if(a[i][j] == 0) continue;
            
            primero = {i , j};

            if((j + 1) < n && (a[i][j+1] == 1)){
                segundo = {i , j +1};
                found = true;
                break;
            }
            if((i + 1) < n && (a[i+1][j] == 1)){
                segundo = {i +1 , j};
                found = true;
                break;
            }
            
        }
        if(found) break;
    }

    pl xd = {-1 , -1};
    if(primero == segundo && primero == xd){
        cout<<"YES\n";
        return;
    }
    else{

        dfs(dfs,primero.first , primero.second);
        dbg("hola ???",cuantos ,(ll)negros.size());
        if(cuantos == (ll)negros.size()){
            cout<<"YES\n";
            return;
        }
        
    }
    auto check=[&](pl pri, pl seg){
        //fila misma
        set<pl> actuales;
        if(pri.first == seg.first){
            ll row = pri.first , guarda = row;
            ll ptr1 = pri.second , ptr2 = seg.second;
            while(row < n){
                if(ptr1 < n && a[row][ptr1] == 1){
                    actuales.insert(make_pair(row,ptr1));
                }
                if(ptr2 < n && a[row][ptr2] == 1){
                    actuales.insert(make_pair(row,ptr2));
                }
                row++;
                ptr1++;
                ptr2++;
            }
            ll ptr3 = pri.second , ptr4 = seg.second;
            while(guarda >=0){
                if(ptr3 >=0 && a[guarda][ptr3] == 1){
                    actuales.insert(make_pair(guarda,ptr3));
                }
                if(ptr4 >=0 && a[guarda][ptr4] == 1){
                    actuales.insert(make_pair(guarda,ptr4));
                }
                guarda--;
                ptr3--;
                ptr4--;
            }

            if(actuales == negros) return true;
            else{
                actuales.clear();
                ll row = pri.first , guarda = row;
                ll ptr1 = pri.second , ptr2 = seg.second;
                while(row < n){
                    if(ptr1 >= 0 && a[row][ptr1] == 1){
                        actuales.insert(make_pair(row,ptr1));
                    }
                    if(ptr2 >= 0 && a[row][ptr2] == 1){
                        actuales.insert(make_pair(row,ptr2));
                    }
                    row++;
                    ptr1--;
                    ptr2--;
                }
                ll ptr3 = pri.second , ptr4 = seg.second;
                while(guarda >=0){
                    if(ptr3 < n && a[guarda][ptr3] == 1){
                        actuales.insert(make_pair(guarda,ptr3));
                    }
                    if(ptr4 < n && a[guarda][ptr4] == 1){
                        actuales.insert(make_pair(guarda,ptr4));
                    }
                    guarda--;
                    ptr3++;
                    ptr4++;
                }
                return actuales == negros;
            }
        }
        else{
            //debe de ser columna misma 
            assert(pri.second == seg.second);
            ll col = pri.second , guarda = col;
            ll ptr1 = pri.first , ptr2 = seg.first;
            while(col < n){
                if(ptr1 < n && a[ptr1][col] == 1){
                    actuales.insert(make_pair(ptr1,col));
                }
                if(ptr2 < n && a[ptr2][col] == 1){
                    actuales.insert(make_pair(ptr2,col));
                }
                col++;
                ptr1++;
                ptr2++;
            }
            ll ptr3 = pri.first , ptr4 = seg.first;
            while(guarda >=0){
                if(ptr3 >=0 && a[ptr3][guarda] == 1){
                    actuales.insert(make_pair(ptr3,guarda));
                }
                if(ptr4 >=0 && a[ptr4][guarda] == 1){
                    actuales.insert(make_pair(ptr4,guarda));
                }
                guarda--;
                ptr3--;
                ptr4--;
            }

            if(actuales == negros)return true;
            else{
                actuales.clear();
                ll col = pri.second , guarda = col;
                ll ptr1 = pri.first , ptr2 = seg.first;
                while(col < n){
                    if(ptr1 >= 0 && a[ptr1][col] == 1){
                        actuales.insert(make_pair(ptr1,col));
                    }
                    if(ptr2 >=0 && a[ptr2][col] == 1){
                        actuales.insert(make_pair(ptr2,col));
                    }
                    col++;
                    ptr1--;
                    ptr2--;
                }
                ll ptr3 = pri.first , ptr4 = seg.first;
                while(guarda >=0){
                    if(ptr3 < n && a[ptr3][guarda] == 1){
                        actuales.insert(make_pair(ptr3,guarda));
                    }
                    if(ptr4  < n && a[ptr4][guarda] == 1){
                        actuales.insert(make_pair(ptr4,guarda));
                    }
                    guarda--;
                    ptr3++;
                    ptr4++;
                }
                return actuales == negros;
            }
        }
    };
    
    dbg(negros);
    if(segundo == xd){
        //no hay 2 seguidos
        dbg("no hay 2 seguidos",primero,segundo);
        for(ll k = 0;k < 4; k++){
            ll newX = primero.first + dx[k] , newY = primero.second + dy[k];
            if(isValid(newX,newY)){
                pl nuevo = {newX,newY};
                dbg(primero, nuevo);
                V<pl> paraordenar = {primero , nuevo};
                sor(paraordenar);
                dbg(paraordenar);
                if(check(paraordenar[0] , paraordenar[1] )){
                    cout<<"YES\n";
                    return;
                }
            }
        }
        cout<<"NO\n";
    }
    else{
        dbg("este es mi pri seg",primero, segundo);
        if(check(primero , segundo)){
            cout<<"YES\n";
        }
        else{
            /*if(primero.first == segundo.first){
                pl porsiacaso1 = {primero.first + 1 , primero.second};
                if(check(primero , porsiacaso1)){
                    cout<<"YES\n";
                }
                else cout<<"NO\n";
            }
            else{
                pl porsiacaso2 = {primero.first  , primero.second -1};
                if(check(porsiacaso2 , primero)){
                    cout<<"YES\n";
                }
                else cout<<"NO\n";
            }*/
           cout<<"NO\n";
        }
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    while(0){
        ll n = rng_ll(1,10);
        V<vl> a(n,vl(n,0));
        for(auto & e :a){
            for(auto & e2 : e){
                e2 = rng_ll(0,1);
            }
        }
        dbg(n);
        for(auto & e : a)dbg(e);
        solve(a);
    }
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        V<vl> a(n,vl(n,0));
        for(ll i = 0;i < n; i++){
            for(ll j = 0;j < n; j++){
                char xd;
                cin>>xd;
                a[i][j] = (xd == '#');
            }
        }
        solve(a);
    }
}