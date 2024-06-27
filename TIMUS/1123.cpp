//? #pragma GCC optimize ("Ofast")
//? #pragma GCC target ("avx,avx2")
//! #pragma GCC optimize ("trapv")
//#undef _GLIBCXX_DEBUG //? for Stress Testing
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "../debugICPC.h"
#define chk(...) if (!(__VA_ARGS__)) cerr << "\033[41m" << "Line(" << __LINE__ << ") -> function(" \
	 << __FUNCTION__  << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")" << "\033[0m" << "\n", exit(0);

#define MACRO(code) do {code} while (false)
#define RAYA MACRO(cerr << "\033[101m" << "================================" << "\033[0m" << endl;)
#else
#define dbg(...)

#define chk(...)
#define RAYA
#endif

const auto beg_time = std::chrono::high_resolution_clock::now();
// https://stackoverflow.com/questions/47980498/accurate-c-c-clock-on-a-multi-core-processor-with-auto-overclock?noredirect=1&lq=1
double time_elapsed() {
	return chrono::duration<double>(std::chrono::high_resolution_clock::now() -
	                                beg_time)
	    .count();
}

// building blocks
using ll  = long long;
using db  = long double; // or double, if TL is tight
using str = string;      // yay python!
//? priority_queue for minimum
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
using ull  = unsigned long long;
//? using i64  = long long;
//? using u64  = uint64_t;
//? using i128 = __int128;
//? using u128 = __uint128_t;
//? using f128 = __float128;
// pairs
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
#define mp make_pair
#define f first
#define s second

#define tcT template <class T
#define tcTU tcT, class U
//! ^ lol this makes everything look weird but I'll try it
tcT > using V = vector<T>;
tcT, size_t SZ > using AR = array<T, SZ>;
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;

// vectors
// oops size(x), rbegin(x), rend(x) need C++17
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()
#define ts to_string



// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)
 

bool isPalindrome(str s){
    ll n=s.size();
    ll i=0,j=n-1;
    bool ok=true;
    while(i<j){
        if(s[i]!=s[j]){
            ok=false;
            break;
        }
        i++;
        j--;
    }
    return ok;
}
ll rng_ll(ll L, ll R) { assert(L <= R);
	return uniform_int_distribution<ll>(L,R)(rng);  }
str resolverRefactorizado(str s){
    while(!isPalindrome(s)){
        ll n=s.size();
        ll idx=n-1;
        while(idx>=0 && s[idx]-'0'==9){
            idx--;
        }
        if(idx==-1 && s[0]=='9'){
            //puro 99999
            str nuevo="1";
            FOR(i,0,n){
                nuevo+='0';
            }
            s=nuevo;
        }
        else if(idx>=0 && s[idx]-'0'<9){
            s[idx]=s[idx]+1;
            FOR(j,idx+1,n){
                s[j]='0';
            }
        }
        else if(idx==n-1){
            s[idx]=s[idx]+1;
        } 
    }
}
str solve(str s) {
    if(isPalindrome(s)) return s;
    ll n=s.size();
    ll i=0,j=n-1;
    bool retrocedio=false;
    while(i<j){
        if(j-i<=1) break;
        if(s[j]>s[i]) retrocedio=true;
        else if(s[j]<s[i]) retrocedio=false;
        s[j]=s[i];
        i++;
        j--;
    }
    if(i==j){
        if(!retrocedio){
            //no hacer nada
        }
        else{
            ll ptrI=i,ptrD=j;
            while(ptrI>=0 && ptrD<n && s[ptrI]==s[ptrD] && s[ptrI]=='9'){
                ptrI--;
                ptrD++;
            }
            if(ptrI==ptrD){
                s[ptrI]=s[ptrI]+1;
            }
            else{
                FOR(k,ptrI+1,ptrD){
                    s[k]='0';
                }
                s[ptrI]=s[ptrI]+1;
                s[ptrD]=s[ptrD]+1;
            }
        }
        
    }
    else{
        if(!retrocedio){
            ll ptrI=i,ptrD=j;
            if(s[ptrI] == s[ptrD]){
                //no hacer nada
            }
            else if(s[ptrI] < s[ptrD]){
                char poner=s[ptrI]+1;
                s[ptrI]=poner;
                s[ptrD]=poner;
            }
            else{
                s[ptrD]=s[ptrI];
            }
        }
        else{
            ll ptrI=i,ptrD=j;
            while(ptrI>=0 && ptrD<n && s[ptrI]==s[ptrD] && s[ptrI]=='9'){
                ptrI--;
                ptrD++;
            }
            if(ptrI == i && ptrD == j){
                if(s[ptrI] <= s[ptrD]){
                    char poner=s[ptrI]+1;
                    s[ptrI]=poner;
                    s[ptrD]=poner;
                }
                else{
                    s[ptrD]=s[ptrI];
                }
            }
            else{
                FOR(k,ptrI+1,ptrD){
                    s[k]='0';
                }
                s[ptrI]=s[ptrI]+1;
                s[ptrD]=s[ptrD]+1;
            } 
        }  
    }
    return s;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    //cin >> t;
    while(0){
        ll n=rng_ll(1,10000000);
        str p=to_string(n);
        str ans1=resolverRefactorizado(p);
        str ans2=solve(p);
        if(ans1!=ans2){
            dbg("xd",p,ans1,ans2);
            assert(false);
        }
        else dbg("ok");
    }
    for(int idx = 0; idx < t; idx++) {
        RAYA;
        RAYA;
        str s;
        cin>>s;
        cout<<solve(s)<<"\n";
        //dbg(brute(s),solve(s));
    }
    RAYA;
    RAYA;

    #ifdef LOCAL
        cerr << fixed << setprecision(5);
        cerr << "\033[42m++++++++++++++++++++\033[0m\n";
        cerr << "\033[42mtime = " << time_elapsed() << "ms\033[0m\n";
        cerr << "\033[42m++++++++++++++++++++\033[0m";
    #endif
}








