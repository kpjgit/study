//1012
#include <bits/stdc++.h>

int T;
int N, M;
int K;
bool board[50][50];
bool vis[50][50];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

std::queue<std::pair<int, int>> q;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> T;
    
    int x, y;
    for(int num = 0; num < T; num++) {
        int ans = 0;
        std:: cin >> M >> N >> K;
        for(int i = 0; i < N; i++) {
            std::fill(board[i], board[i] + M, 0);
            std::fill(vis[i], vis[i] + M, 0);
        }

        for(int i = 0; i < K; i++) {
            std::cin >> x >> y;
            board[y][x] = 1;
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(board[i][j] != 1 || vis[i][j] == 1) continue;

                q.push({i, j});
                vis[i][j] = 1;
                ans++;
                while(!q.empty()) {
                    std::pair<int, int> cur = q.front();
                    q.pop();

                    for(int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                        if(vis[nx][ny] == 1 || board[nx][ny] != 1) continue;
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }

        std::cout << ans << '\n';
    }
}