//7576
#include <bits/stdc++.h>

int N, M;

int box[1001][1001];
int dist[1001][1001];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

std::queue<std::pair<int, int>> q;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> M >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> box[i][j];

            if(box[i][j] == 1) {
                q.push({i, j});
                dist[i][j] = 0;
            } else if(box[i][j] == 0) dist[i][j] = -1;
        }
    }

    while(!q.empty()) {
        std::pair<int, int> cur = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(dist[nx][ny] >= 0 || box[nx][ny] == -1) continue;

            q.push({nx, ny});
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(dist[i][j] > ans) ans = dist[i][j];
            if(dist[i][j] == -1) {
                std::cout << -1;
                return 0;
            }
        }
    }

    std::cout << ans;
}