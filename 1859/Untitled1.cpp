#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int m, k, a1, ak;
        cin >> m >> k >> a1 >> ak;

        if (a1 >= m) {
            cout << "0\n";
            continue;
        }

        int remaining_regular_coins = a1;
        int fancy_coins_needed = 0;

        while (remaining_regular_coins < m) {
            int regular_coins_needed = (k - remaining_regular_coins % k) % k;
            int fancy_coins_used = 0;

            if (ak > 0) {
                fancy_coins_used = (regular_coins_needed + ak - 1) / ak;
            }

            if (remaining_regular_coins + regular_coins_needed > m) {
                fancy_coins_used = (m - remaining_regular_coins + ak - 1) / ak;
            }

            fancy_coins_needed += fancy_coins_used;
            remaining_regular_coins += regular_coins_needed;
        }

        cout << fancy_coins_needed << "\n";
    }

    return 0;
}


