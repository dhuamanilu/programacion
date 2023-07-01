#include <iostream>
#include <vector>
#include <climits>
const int MAXN=100;
long long n;
vector<long long> a(MAXN+1);
vector<long long> f(MAXN+1, -1);
using namespace std;
long long calc_f(long long k) {
    if (f[k]!=-1) {
        return f[k];
    }
    if (k<=n) {
        return f[k]=a[k];
    }
    long long ans = INT_MAX;
    for (long long i=1;i<=k/2;i++) {
        long long j=k-i;
        ans=min(ans,calc_f(i)+calc_f(j));
    }
    return f[k]=ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long N;
    cin>>n>>N;
    for(long long i=1;i<=n;i++) {
        cin>>a[i];
    }
    for (long long k=1;k<=MAXN;k++) {
        calc_f(k);
    }
    while (N--) {
        long long k;
        cin>>k;
        cout<<calc_f(k)<<"\n";
    }
    return 0;
}
