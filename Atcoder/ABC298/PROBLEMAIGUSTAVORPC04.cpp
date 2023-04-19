#include <iostream>

using namespace std;

void solve() {
    long long n, k;

    cin >> n >> k;

    long long a[n], b[k], c[k]{0};

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < k; i++) {
        cin >> b[i];
    }

    long double growth = 0;
    const long double GROWTH_PER_DEGREE = 0.2;

    for(int i = 0; i < n; i++) {
        growth += -a[i] * GROWTH_PER_DEGREE;

        if(growth < 0) {
            growth = 0;
        }

        for(int j = 0; j < k; j++) {
            if(growth >= b[j]) {
                c[j]++;
            }
        }
    }

    for(int i = 0; i < k; i++) {
        cout << c[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}
