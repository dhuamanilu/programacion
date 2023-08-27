#include <bits/stdc++.h>
using namespace std;

const int N = 100 + 5;
const int inf = 2e9 + 10;

int n;
int m;
int d[N][N];

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			d[i][j] = i == j ? 0 : inf;
		}
	}
	for(int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
        u--;
        v--;
		d[u][v] = min(d[u][v], -w);
	}
	// Floyd-Warshall
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(d[i][k] == inf or d[k][j] == inf) continue;
				if(d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] + d[k][j];
			}
		}
	}
	// Termina Floyd-Warshall
	for(int i = 0; i < n; i++) {
		if(d[i][i] < 0) {
			puts("NEGATIVE CYCLE");
			return 0;
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(d[i][j] == inf) printf("INF");
			else printf("%d", d[i][j]);
			putchar(j + 1 == n ? '\n' : ' ');
		}
	}
	return 0;
}
