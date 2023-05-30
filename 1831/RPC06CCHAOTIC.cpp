#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n, q;
    cin >> n >> q;

    while (q--) {
        char event;
        int segment;
        cin >> event >> segment;

        if (event == '-') {
            updateSegmentTree(tree, 0, segment, true);
        } else if (event == '+') {
            updateSegmentTree(tree, 0, segment, false);
        } else if (event == '?') {
            int a, b;
                cin >> b;
            a=segment;
            bool isBlocked = querySegmentTree(tree, 0, a, b);

            if (isBlocked) {
                cout << "impossible\n";
            } else {
                cout << "possible\n";
            }
        }
    }

    return 0;
}










