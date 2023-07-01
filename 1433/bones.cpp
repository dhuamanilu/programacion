#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Slice {
    long long spicy;
    long long increase;

    Slice(long long spicy, long long increase) : spicy(spicy), increase(increase) {}
};

void merge(Slice& a, const Slice& b, Slice& res) {
    Slice tmp_a = a; // Make a copy of a
    res.spicy = min(a.spicy, b.spicy);
    res.increase = tmp_a.increase + b.increase;
}

int main() {
    int n;
    cin >> n;

    vector<Slice> slices;
    for (int i = 0; i < n; i++) {
        long long spicy;
        cin >> spicy;
        slices.emplace_back(spicy, spicy);
    }

    while (slices.size() > 1) {
        bool merged = false;
        for (auto it = slices.begin(); it != slices.end(); ) {
            auto next_it = next(it);
            if (next_it == slices.end()) {
                next_it = slices.begin();
            }

            if (it->spicy <= slices.front().increase && next_it->spicy <= slices.back().increase) {
                Slice res(0, 0);
                merge(*it, *next_it, res);
                slices.front().increase = res.increase;
                slices.front().spicy = res.spicy;
                it = slices.erase(it);
                slices.pop_back();
                merged = true;
            } else {
                it++;
            }
        }

        if (!merged) {
            break;
        }
    }

    if (slices.size() == 1 && slices.front().spicy <= slices.front().increase) {
        cout << slices.front().increase << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
