#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Cell {
    int x, y, dist;
};

int main() {
    int M, N;
    cin >> M >> N;
    vector<vector<int>> grid(M, vector<int>(N)); // Initialize grid M x N
    for (int i = 0; i < M; ++i) { // zero-based indices
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }

    int src_x, src_y;
    cin >> src_x >> src_y;
    int dest_x, dest_y;
    cin >> dest_x >> dest_y;
    int dx, dy;
    cin >> dx >> dy;

    // Movement directions
    int dirX[4] = {dx, dy, -dy, -dx};
    int dirY[4] = {dy, -dx, dx, -dy};

    // Check if source or destination is blocked or out of bounds
    if (src_x < 0 || src_x >= M || src_y < 0 || src_y >= N || grid[src_x][src_y] == 1 ||
        dest_x < 0 || dest_x >= M || dest_y < 0 || dest_y >= N || grid[dest_x][dest_y] == 1) {
        cout << -1 << endl;
        return 0;
    }

    vector<vector<bool>> visited(M, vector<bool>(N, false));
    queue<Cell> q;
    q.push({src_x, src_y, 0});
    visited[src_x][src_y] = true;

    while (!q.empty()) {
        Cell current = q.front();
        q.pop();

        if (current.x == dest_x && current.y == dest_y) {
            cout << current.dist << endl;
            return 0;
        }

        for (int i = 0; i < 4; ++i) {
            int new_x = current.x + dirX[i];
            int new_y = current.y + dirY[i];

            if (new_x >= 0 && new_x < M && new_y >= 0 && new_y < N &&
                grid[new_x][new_y] == 0 && !visited[new_x][new_y]) {
                visited[new_x][new_y] = true;
                q.push({new_x, new_y, current.dist + 1});
            }
        }
    }

    // Destination not reachable
    cout << -1 << endl;
    return 0;
}
