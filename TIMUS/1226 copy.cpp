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

// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)


void solve() {
	int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    if(n%2==0){
        cout<<(a[n/2] + a[(n/2) - 1])/2<<"\n";
    }
    else{
        cout<<a[n/2]<<"\n";
    }
   
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    #ifdef LOCAL
        cerr << fixed << setprecision(5);
        cerr << "\033[42m++++++++++++++++++++\033[0m\n";
        cerr << "\033[42mtime = " << time_elapsed() << "ms\033[0m\n";
        cerr << "\033[42m++++++++++++++++++++\033[0m";
    #endif
}








