#include <iostream>
#include <vector>
using namespace std;

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

bool isValid(int r, int c, int R, int C) {
    return r >= 0 && r < R && c >= 0 && c < C;
}

bool canCaptureWhiteStones(vector<string>& board, int R, int C) {
    vector<vector<bool>> visited(R, vector<bool>(C, false));

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (board[r][c] == 'B' || visited[r][c]) continue;

            bool canCapture = true;
            vector<pair<int, int>> group;
            vector<pair<int, int>> q;

            q.push_back({r, c});

            while (!q.empty()) {
                int curR = q.back().first;
                int curC = q.back().second;
                q.pop_back();

                if (visited[curR][curC]) continue;
                visited[curR][curC] = true;

                group.push_back({curR, curC});

                for (int i = 0; i < 4; i++) {
                    int nr = curR + dr[i];
                    int nc = curC + dc[i];

                    if (isValid(nr, nc, R, C) && board[nr][nc] == '.') {
                        canCapture = false;
                    } else if (isValid(nr, nc, R, C) && board[nr][nc] == 'W' && !visited[nr][nc]) {
                        q.push_back({nr, nc});
                    }
                }
            }

            if (canCapture) return true;
        }
    }

    return false;
}

int main() {
    if (fopen("ready_go_part_1_validation_input.txt", "r")) {
		freopen("ready_go_part_1_validation_input.txt", "r", stdin);
		freopen("outA.txt", "w", stdout);
    }
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int R, C;
        cin >> R >> C;
        vector<string> board(R);
        for (int i = 0; i < R; i++) {
            cin >> board[i];
        }

        bool canCapture = canCaptureWhiteStones(board, R, C);

        cout << "Case #" << t << ": " << (canCapture ? "YES" : "NO") << endl;
    }

    return 0;
}
