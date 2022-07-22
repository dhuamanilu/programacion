#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


typedef pair<int, int> pi;

typedef vector<int> vi;
typedef vector<ll> vll;
#define FOR(i, a, b) for (int i=a; i<(b); i++)

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

int main(){


    cout<<"14000 14000"<<endl;
    srand(time(0));
    for(int i = 0; i < 14000; i++){
        ll a=(rand()%14000);
        if(a==0) a++;
        cout <<a<<endl;
    }
    for(int i = 0; i < 14000; i++){
        ll a=(rand()%14000);
        ll b=(rand()%14000);
        if(a==0) a++;
        if(b==0) b++;
        cout <<a<<" "<<b<<endl;
    }
    cout<<endl;
	return 0;
}
