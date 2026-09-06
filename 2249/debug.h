#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

//? building blocks
using ll = long long;
using ull = unsigned long long;
using db = long double; // or double, if TL is tight
using str = string; // yay python!
//? using i64 = long long; //? for Number Theory related
//? using u64 = uint64_t; //? for Number Theory related
//? using i128 = __int128; //? for Number Theory related
//? using u128 = __uint128_t; //? for Number Theory related
//? template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>; // minima

//? pairs
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;

#define mp make_pair
#define f first
#define s second

//? Source: https://stackoverflow.com/a/31116392/12128483
template<typename Type, unsigned N, unsigned Last>
struct TuplePrinter {
    static void print(std::ostream& out, const Type& value) {
        out << std::get<N>(value) << ", ";
        TuplePrinter<Type, N + 1, Last>::print(out, value);
    }
};

template<typename Type, unsigned N>
struct TuplePrinter<Type, N, N> {
    static void print(std::ostream& out, const Type& value) {
        out << std::get<N>(value);
    }
};

template<typename... Types>
std::ostream& operator<<(std::ostream& out, const std::tuple<Types...>& value) {
    out << '(';
    TuplePrinter<std::tuple<Types...>, 0, sizeof...(Types) - 1>::print(out, value);
    return out << ')';
}



// benq - print any container + pair
template<typename T, typename = void> struct is_iterable : false_type {};
template<typename T> struct is_iterable<T, void_t<decltype(begin(declval<T>())),decltype(end(declval<T>()))>> : true_type {};
template<typename T> typename enable_if<is_iterable<T>::value&&!is_same<T, string>::value,ostream&>::type operator<<(ostream &cout, T const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename T> typename enable_if<is_iterable<T>::value&&!is_same<T, string>::value,ostream&>::type operator<<(ostream &cout, T const &v) {
    cout << "[";
    for (auto it = v.begin(); it != v.end();) {
        cout << *it;
        if (++it != v.end()) cout << ", ";
    }
    return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
    cin >> p.first;
    return cin >> p.second;
}



template<typename T> void debug(string s, T x) {cerr << "\033[1;34m" << s << "\033[0;32m = \033[35m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
        if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;34m" << s.substr(0, i) << "\033[0;32m = \033[35m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

#define MACRO(code) do {code} while (false)
#define dbg(...) MACRO(cerr << "Line(" << __LINE__ << "): "; debug(#__VA_ARGS__, __VA_ARGS__);)
#define chk(...) if (!(__VA_ARGS__)) cerr << "\033[41m" << "Line(" << __LINE__ << ") -> function(" \
	 << __FUNCTION__  << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")" << "\033[0m" << "\n", exit(0);



// for debugging!
#define RAYA MACRO(cerr << "\033[101m" << "================================" << "\033[0m" << endl;)