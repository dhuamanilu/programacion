// source: https://codeforces.com/blog/entry/62393
#include <cassert>
#include <ctime>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int N = 2e5;

vector<int> gen_multiples(int x) {
	int cur = 1, rem = 1;
	vector<int> res;
	for (int i = 1; i <= N; i++) {
		assert(1 <= cur && cur <= 1e9);
		res.push_back(cur);
		cur += x;
		if (cur > 1e9) {
			++rem;
			cur = rem;
		}
	}
	return res;
}

double insert_numbers(vector<int> nums) {
	clock_t begin = clock();
	unordered_map<long long, int> m;
	for (int n : nums) m[n];
	return (double)(clock() - begin) / CLOCKS_PER_SEC;
}

int main() {
	const long prime_list[]{
	    107897ul, 116731ul, 126271ul, 136607ul, 147793ul, 159871ul, 172933ul,
	    187091ul, 202409ul, 218971ul, 236897ul, 256279ul, 277261ul, 299951ul,
	};  // https://github.com/gcc-mirror/gcc/blob/5bea0e90e58d971cf3e67f784a116d81a20b927a/libstdc%2B%2B-v3/src/shared/hashtable-aux.cc
	for (int prime : prime_list) {
		cerr << "testing " << prime << ": ";
		vector<int> multiples = gen_multiples(prime);
		double runtime = insert_numbers(multiples);
		cerr << runtime << "\n";
		if (runtime > 1) {
			// output hack case for https://cses.fi/problemset/task/1640/
			cout << N << " 1\n";
			for (int i = 0; i < N; ++i) {
				if (i) cout << " ";
				cout << multiples[i];
			}
			cout << "\n";
			exit(0);
		}
	}
}








