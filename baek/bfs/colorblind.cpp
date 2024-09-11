//10026
#include <bits/stdc++.h>

int N;

char board[100][100];
bool vis[100][100];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int find() {
    int ans = 0;
    std::queue<std::pair<int, int>> q;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(vis[i][j] == 1) continue;
            char color = board[i][j];
            q.push({i, j});
            vis[i][j] = 1;
            ans++;

            while(!q.empty()) {
                auto cur = q.front();
                q.pop();

                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                    if(vis[nx][ny] == 1 || board[nx][ny] != color) continue;
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }
    }

    return ans;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> board[i][j];
        }
    }
    std::cout << find() << ' ';

    for(int i = 0; i < N; i++) {
        std::fill(vis[i], vis[i] + N, 0);
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(board[i][j] == 'R') board[i][j] = 'G';
        }
    }
    std::cout << find();
}