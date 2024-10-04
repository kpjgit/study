//3190
#include <bits/stdc++.h>

int N, K, L;
int board[100][100];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

std::queue<std::pair<int, int>> q;
std::queue<std::pair<int, char>> rot;
int x, y;
int dir = 1;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> K;
    int x0, y0;
    for(int i = 0; i < K; i++) {
        std::cin >> x0 >> y0;
        board[x0 - 1][y0 - 1] = 1;
    }

    std::cin >> L;
    int X;
    char C;
    for(int i = 0; i < L; i++) {
        std::cin >> X >> C;
        rot.push({X, C});
    }

    q.push({x, y});
    board[x][y] = 2;
    int ans = 0;

    int timer;
    char nxt;
    std::tie(timer, nxt) = rot.front();
    rot.pop();
    while(true) {
        ans++;
        x += dx[dir];
        y += dy[dir];
        q.push({x, y});
        
        if(x < 0 || y < 0 || x >= N || y >= N) break;
        
        if(board[x][y] == 1) {
            board[x][y] = 2;
        } else if(board[x][y] == 2) break;
        else {
            board[x][y] = 2;
            auto en = q.front();
            q.pop();
            board[en.first][en.second] = 0;
        }

        if(ans == timer) {
            if(nxt == 'L') {
                dir = (dir + 3) % 4;
            } else {
                dir = (dir + 1) % 4;
            }

            std::tie(timer, nxt) = rot.front();
            rot.pop();
        }
    }

    std::cout << ans;
}