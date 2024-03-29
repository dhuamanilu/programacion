#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
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
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;
const int N=1000+3;
struct Sieve {
    struct PrimeIterator {
        int prime;
        int count;
        int num;
        const Sieve& sieve;

        PrimeIterator(int num, const Sieve& sieve) : num(num), sieve(sieve) {
            step();
        }

        void step() {
            prime = sieve.mn[num];
            count = 0;
            while (num != 1 && sieve.mn[num] == prime) {
                num /= sieve.mn[num];
                ++count;
            }
        }

        bool operator == (const PrimeIterator& other) const {
            return tie(prime, count, num) == tie(other.prime, other.count, other.num);
        }
        bool operator != (const PrimeIterator& other) const {
            return !(*this == other);
        }

        PrimeIterator& operator ++ () {
            step();
            return *this;
        }

        pair<int, int> operator * () const {
            return {prime, count};
        }
    };

    struct PrimeIteratorContainer {
        int num;
        const Sieve& sieve;
        using iterator = PrimeIterator;

        PrimeIteratorContainer(int num, const Sieve& sieve) : num(num), sieve(sieve) {}

        PrimeIterator begin() const {
            return PrimeIterator(num, sieve);
        }

        PrimeIterator end() const {
            return PrimeIterator(1, sieve);
        }

        vector<pair<int, int>> collect() const {
            vector<pair<int, int>> result;
            for (auto p : *this)
                result.push_back(p);
            return result;
        }
    };

    template<typename U, typename V>
    struct DoubleIterator {
        U u;
        V v;
        U::iterator uit;
        V::iterator vit;
        int prime;
        int count;

        DoubleIterator(const U& u, const V& v, U::iterator uit, V::iterator vit) : u(u), v(v), uit(uit), vit(vit) {
            tie(prime, count) = this->operator*();
        }

        DoubleIterator& operator ++ () {
            if (uit == u.end()) {
                ++vit;
            } else if (vit == v.end()) {
                ++uit;
            } else if ((*uit).first < (*vit).first) {
                ++uit;
            } else if ((*uit).first > (*vit).first) {
                ++vit;
            } else {
                ++uit;
                ++vit;
            }
            return *this;
        }

        bool operator == (const DoubleIterator& other) const {
            return tie(uit, vit) == tie(other.uit, other.vit);
        }
        bool operator != (const DoubleIterator& other) const {
            return !(*this == other);
        }

        pair<int, int> operator * () const {
            if (uit == u.end()) return *vit;
            if (vit == v.end()) return *uit;
            if ((*uit).first < (*vit).first) return *uit;
            if ((*uit).first > (*vit).first) return *vit;
            return {(*uit).first, (*uit).second + (*vit).second};
        }
    };

    template<typename U, typename V>
    struct DoubleIteratorContainer {
        using iterator = DoubleIterator<U, V>;
        U u;
        V v;

        DoubleIteratorContainer(const U& u, const V& v) : u(u), v(v) {}

        iterator begin() const {
            return iterator(u, v, u.begin(), v.begin());
        }

        iterator end() const {
            return iterator(u, v, u.end(), v.end());
        }

        vector<pair<int, int>> collect() const {
            vector<pair<int, int>> result;
            for (auto p : *this)
                result.push_back(p);
            return result;
        }
    };

    vector<bool> isp;
    vector<int> primes;
    vector<int> mn;

    Sieve(int n, bool gen_primes = false, bool gen_mn = false) {
        isp.assign(n + 1, true); isp[0] = isp[1] = false;
        for (int i = 2; i * i <= n; ++i)
            if (isp[i])
                for (int j = i * i; j <= n; j += i)
                    isp[j] = false;

        if (gen_primes)
            for (int i = 2; i <= n; ++i)
                if (isp[i])
                    primes.push_back(i);

        if (gen_mn) {
            mn.assign(n + 1, -1);
            for (int i = 2; i <= n; ++i) {
                if (isp[i]) {
                    mn[i] = i;
                    if ((ll)i * i <= n)
                        for (int j = i * i; j <= n; j += i)
                            if (mn[j] == -1)
                                mn[j] = i;
                }
            }
        }
    }

    bool is_prime(int k) const {
        return isp[k];
    }

    bool operator[](int k) const {
        return isp[k];
    }

    // can be used as vector<pair<int, int>>, as in function phi() below
    // except doesn't create a vector to avoid heap allocations
    // can be transformed into vector<pair<int, int>> with .collect()
    auto get_prime_divs(int p) const {
        return PrimeIteratorContainer(p, *this);
    }

    // if you want to get prime divs for n = a * b * c where max(a, b, c) < size(sieve), then call get_prime_divs(a, b, c)
    template<typename... Args>
    auto get_prime_divs(int p, Args... args) const {
        return DoubleIteratorContainer(PrimeIteratorContainer(p, *this), get_prime_divs(args...));
    }

    int phi(int n) const {
        auto v = get_prime_divs(n);
        for (auto [p, c] : v)
            n = n / p * (p - 1);
        return n;
    }
};
Sieve sieve(sqrt(1e9) + 10, true);
void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    FOR(i,0,n){
        cin>>a[i];
    }
    if(n<=10){
        FOR(i,0,n){
            FOR(j,i+1,n){
                if(__gcd(a[i],a[j])>1){
                    cout<<"YES\n";
                    return;
                }
            }
        }
        cout<<"NO\n";
        return;
    }
    auto & p = sieve.primes;
    bool ok=false;
    for(auto & e : p){
        ll cont=0;
        FOR(i,0,n){
            if(a[i]%e==0) cont++;
        }
        if(cont>1){
            ok=true;
            break;
        }
    }
    if(ok){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
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








