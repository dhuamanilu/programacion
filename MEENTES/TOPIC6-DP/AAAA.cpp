#include <iostream>
#include <vector>

using namespace std;

const int MAX_R = 19;
const int MAX_C = 19;

char board[MAX_R][MAX_C];

bool canCapture(int r, int c) {
    if (board[r][c] != '.') {
        return false;
    }

    board[r][c] = 'B';

    bool capturedAny = false;

    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            if (dr == 0 && dc == 0) {
                continue;
            }

            int nr = r + dr;
            int nc = c + dc;

            if (nr < 0 || nr >= MAX_R || nc < 0 || nc >= MAX_C || board[nr][nc] != 'W') {
                continue;
            }

            vector<pair<int, int>> toCheck;
            toCheck.push_back({nr, nc});

            bool groupCaptured = true;

            for (int i = 0; i < toCheck.size(); i++) {
                int curR = toCheck[i].first;
                int curC = toCheck[i].second;

                board[curR][curC] = '.';

                for (int dr2 = -1; dr2 <= 1; dr2++) {
                    for (int dc2 = -1; dc2 <= 1; dc2++) {
                        if (dr2 == 0 && dc2 == 0) {
                            continue;
                        }

                        int nnr = curR + dr2;
                        int nnc = curC + dc2;

                        if (nnr < 0 || nnr >= MAX_R || nnc < 0 || nnc >= MAX_C || board[nnr][nnc] != 'W') {
                            continue;
                        }

                        toCheck.push_back({nnr, nnc});
                        groupCaptured = false;
                    }
                }
            }

            if (groupCaptured) {
                capturedAny = true;
            }
        }
    }

    board[r][c] = '.';

    return capturedAny;
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int R, C;
        cin >> R >> C;

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                cin >> board[r][c];
            }
        }

        bool canCaptureAny = false;

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (canCapture(r, c)) {
                    canCaptureAny = true;
                    break;
                }
            }
        }

        cout << "Case #" << t << ": " << (canCaptureAny ? "YES" : "NO") << endl;
    }

    return 0;
}
