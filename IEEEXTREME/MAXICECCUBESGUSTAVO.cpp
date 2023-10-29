#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct CoffeeShop {
  int x;
  int y;
  int iceCubes;

  bool operator>(const CoffeeShop& other) const {
    return iceCubes > other.iceCubes;
  }
};

int findMaxIceCubes(vector<vector<int>> &grid, int K, int B) {
  priority_queue<CoffeeShop, vector<CoffeeShop>, greater<CoffeeShop>> pq;

  pq.push({0, 0, grid[0][0]});

  int maxIceCubes = 0;

  while (!pq.empty()) {
    CoffeeShop currentCoffeeShop = pq.top();
    pq.pop();

    if (currentCoffeeShop.x == grid.size() - 1 && currentCoffeeShop.y == grid[0].size() - 1) {
      return maxIceCubes;
    }

    if (currentCoffeeShop.x + 1 < grid.size()) {
      pq.push({currentCoffeeShop.x + 1, currentCoffeeShop.y, grid[currentCoffeeShop.x + 1][currentCoffeeShop.y]});
    }
    if (currentCoffeeShop.y + 1 < grid[0].size()) {
      pq.push({currentCoffeeShop.x, currentCoffeeShop.y + 1, grid[currentCoffeeShop.x][currentCoffeeShop.y + 1]});
    }

    vector<CoffeeShop> path;
    path.push_back(currentCoffeeShop);

    while (!pq.empty()) {
      CoffeeShop nextCoffeeShop = pq.top();
      pq.pop();

      if (nextCoffeeShop.x == grid.size() - 1 && nextCoffeeShop.y == grid[0].size() - 1) {
        path.push_back(nextCoffeeShop);

        if (isPathValid(path, K, B)) {
          maxIceCubes = max(maxIceCubes, currentCoffeeShop.iceCubes + nextCoffeeShop.iceCubes);
        }

        break;
      }

      path.push_back(nextCoffeeShop);
    }
  }

  return -1;
}

int main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    int N, M, K, B;
    cin >> N >> M >> K >> B;

    vector<vector<int>> grid(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        cin >> grid[i][j];
      }
    }

    int maxIceCubes = findMaxIceCubes(grid, K, B);

    if (maxIceCubes == -1) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      cout << "Case " << i + 1 << ": " << maxIceCubes << endl;
    }
  }

  return 0;
}



