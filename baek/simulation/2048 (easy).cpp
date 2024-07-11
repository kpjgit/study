//12100
#include <bits/stdc++.h>

int board[30][30];
int board2[30][30];
int n;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void move(int curx, int cury, int dir);
void select(int dir) {
    if(dir == 0) {
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j < n; j++) {
                move(i, j, dir);
            }
        }
    }

    if(dir == 1) {
        for(int i = 0; i < n; i++) {
            for(int j = n - 1; j >= 0; j--) {
                move(i, j, dir);
            }
        }
    }

    if(dir == 2) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                move(i, j, dir);
            }
        }
    }

    if(dir == 3) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                move(i, j, dir);
            }
        }
    }
}

void move(int curx, int cury, int dir) {
    int x = curx;
    int y = cury;
    while(1) {
        x += dx[dir];
        y += dy[dir];
        if(x < 0 || x >= n || y < 0 || y >= n) break;
        if(board2[x][y] == 0) {
            board2[x][y] = board2[curx][cury];
            board2[curx][cury] = 0;
            curx = x;
            cury = y;
        } else if(board2[x][y] == board2[curx][cury]) {
            board2[x][y] *= 2;
            board2[curx][cury] = 0;
            break;
        } else break;
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int ans = 0;

    std::cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            std::cin >> board[i][j];
        }
    }

    for(int temp = 0; temp < 1 << (2 * 5) ; temp++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                board2[i][j] = board[i][j];
            }
        }

        int brute = temp;
        for(int i = 0; i < 5; i++) {
            int dir = brute % 4;
            brute /= 4;
            select(dir);
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ans = std::max(ans, board2[i][j]);
            }
        }
    }

    std::cout << ans << '\n';
}