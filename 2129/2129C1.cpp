    #pragma GCC optimize ("Ofast")
//? #pragma GCC target ("avx,avx2")
//#pragma GCC optimize ("trapv")
#undef _GLIBCXX_DEBUG //? for Stress Testing
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

bool isRegular(string &xd){
    ll val=0;
    for(auto &e  :xd){
        if(e=='('){
            val++;
        }
        else val--;
        if(val < 0) return 0;
    }
    return (val==0ll);
}
ll contar(string &arr){
    ll val=0,n=arr.size();
    for(ll i=0;i<n;i++){
        string xd="";
        for(ll j=i;j<n;j++){
            xd+=(arr[j]);
            if(isRegular(xd)) val++;
        }
    }
    return val;
}
void gen(ll n){
    const int tar=6;
    auto ver=[&](string &a,vl &way){
        set<ll> outcomes;
        auto explore=[&](auto &&explore,string &valor,ll idx){
            if(idx==tar){
                ll val=contar(valor);
                outcomes.insert(val);
                return;
            }
            string nuevo1=valor;
            nuevo1[way[idx]]='(';
            explore(explore,nuevo1,idx+1);
            string nuevo2=valor;
            nuevo2[way[idx]]=')';
            explore(explore,nuevo2,idx+1);
        };
        string ini=a;
        explore(explore,ini,0);
        //dbg((ll)outcomes.size());
        return (ll)outcomes.size()==(1ll<<tar);
    };
    V<vl> maneras;
    auto ways=[&](auto &&ways,vl chosen,ll idx){
        if(idx >=n){
            if((ll)chosen.size()==tar){
                maneras.push_back(chosen);
            }
            return;
        }
        if((ll)chosen.size()==tar){
            maneras.push_back(chosen);
            return;
        }
        vl nuevo=chosen;
        nuevo.push_back(idx);
        ways(ways,nuevo,idx+1);
        ways(ways,chosen,idx+1);
    };
    vl cial={};
    ways(ways,cial,0);
    //dbg(maneras);
    for(ll k=0;k<(1ll<<(n));k++){
        string a(n,'-');
        for(ll it=0;it<(n);it++){
            if((1ll<<it)&k){
                a[it]=')';
            }
            else a[it]='(';
        }
        for(auto & way : maneras){
            if(ver(a,way)){
                dbg("gosu",a,way);
                assert(false);
            }
            else{
                //dbg("still searching");
            }
        }
    }
    
    
}
bool estoy=false;
ll ops=0;
string mistr;
ll ask22(vl &arr){
    ops++;
    if(ops > 550){
        dbg("que fue",ops,estoy,arr,mistr);
        //assert(false);
    }
    string xd="";
    for(auto & e : arr){
        assert(e>=1 && e<=(mistr.size()));
        xd+=mistr[e-1];
    }
    return contar(xd);
}
ll ask11(vl &arr){
    ll tam=arr.size();
    cout<<"? "<<tam<<" ";
    for(auto & e : arr){
        cout<<e<<" ";
    }
    cout.flush();
    ll res;
    cin>>res;
    return res;
}
str solve(ll n){
    auto ask=[](vl &arr){
        if(estoy){
            return ask22(arr);
        }
        else{
            return ask11(arr);
        }
    };
    ll s=1,e=n,m=s+(e-s)/2,guarda=-1;
    while(s<=e){
        m=s+(e-s)/2;
        vl a(m);
        iota(all(a),1ll);
        ll val=ask(a);
        if(val>0){
            guarda=m;
            e=m-1;
        }
        else{
            s=m+1;
        }
    }
    
    if(guarda==-1){
        ll i=1,j=n;
        str res(n,'4');
        while(i<j){
            vl b={j,i};
            ll val=ask(b);
            if(val>0){
                res[i-1]=')';
                res[j-1]='(';
                i++;
                j--;
            }
            else{
                //desde i hasta j todo es de un solo valor
                //ademas a de 1 es cierra y a de n es abre
                vl c={n,i};
                ll val2=ask(c);
                if(val2>0){
                    for(ll it=i;it<=j;it++){
                        res[it-1]=')';
                    }
                } 
                else{
                    for(ll it=i;it<=j;it++){
                        res[it-1]='(';
                    }
                }
                break;
            }
        }
        if(i==j){
            vl c={n,i};
            ll val2=ask(c);
            if(val2>0){
                res[i-1]=')';
            } 
            else{
                res[i-1]='(';
            }
        }
        bool ok=true;
        for(auto & e : res){
            if(e!='(' && e!=')'){
                ok=false;
                break;
            }
        }
        assert(ok);
        return res;
    }
    else{
        str res(n,'4');
        //dbg(guarda);
        ll abre=guarda-1,cierra=guarda;
        res[abre-1]='(';
        res[cierra-1]=')';
        vl magic={abre,cierra,abre,-1,abre,-1};
        for(ll i=1;i<=n;i++){
            if(i==abre || i==cierra)continue;
            if((i+1)!=abre && ((i+1)<=n)){
                vl b=magic;
                b[3]=i;
                b[5]=i+1;
                ll val=ask(b);
                if(val==1){
                    res[i-1]='(';
                    res[i]='(';
                }
                else if(val==2){
                    res[i-1]='(';
                    res[i]=')';
                }
                else if(val==3){
                    res[i-1]=')';
                    res[i]='(';
                }
                else{
                    assert(val==6);
                    res[i-1]=')';
                    res[i]=')';
                }
                i++;
            }
            else{
                vl c={abre,i};
                ll val2=ask(c);
                if(val2>0){
                    res[i-1]=')';
                } 
                else{
                    res[i-1]='(';
                }
            }
        }
        bool ok=true;
        for(auto & e : res){
            if(e!='(' && e!=')'){
                ok=false;
                break;
            }
        }
        assert(ok);
        return res;
    }
}
int main() {
    //cin.tie(0)->sync_with_stdio(0);
    
    ll t=1;
    cin>>t;
    gen(14);
    auto guess=[](string &s){
        cout<<"! "<<s<<endl;
        cout.flush();
    };
    while(0){
        estoy=true;
        ll tama=rng_ll(1,1000);
        mistr.clear();
        mistr.resize(tama);
        vl cont(2,0);
        for(ll i=0;i<tama;i++){
            ll xd=rng_ll(0,1);
            cont[xd]++;
            if(xd){
                mistr[i]=')';
            }
            else{
                mistr[i]='(';
            }
        }
        if(cont[0]==0 || cont[1]==0) continue;
        string mians=solve(tama);
        dbg("final",ops);

        if(mians!=mistr){
            dbg("xd",mians,mistr);
            assert(false);
        }
        else{
            if(ops > 550){
                dbg("me pase",ops,mistr,mistr.size());
                assert(false);
            }
            else dbg("ok");
        }
        
    }
    while(t--){
        ll n;
        cin>>n;
        string res=solve(n);
        guess(res);
    }
}