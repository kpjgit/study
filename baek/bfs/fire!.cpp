//4179
#include <bits/stdc++.h>

int R, C;
std::string maze[1001];
int dist_J[1001][1001];
int dist_F[1001][1001];
std::queue<std::pair<int, int>> q_J;
std::queue<std::pair<int, int>> q_F;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> R >> C;
    for(int i = 0; i < R; i++) {
        std::cin >> maze[i];
        for(int j = 0; j < C; j++) {
            if(maze[i][j] == 'J') {
                dist_J[i][j] = 1;
                q_J.push({i, j});
            }

            if(maze[i][j] == 'F') {
                dist_F[i][j] = 1;
                q_F.push({i, j});
            }
        }
    }

    while(!q_F.empty()) {
        std::pair<int, int> cur = q_F.front();
        q_F.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            if(dist_F[nx][ny] > 0 || maze[nx][ny] == '#') continue;
            dist_F[nx][ny] = dist_F[cur.first][cur.second] + 1;
            q_F.push({nx, ny});
        }
    }

    while(!q_J.empty()) {
        std::pair<int, int> cur = q_J.front();
        q_J.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || ny < 0 || nx >= R || ny >= C) {
                std::cout << dist_J[cur.first][cur.second];
                return 0;
            }
            if(dist_J[nx][ny] > 0 || maze[nx][ny] == '#') continue;
            if(dist_F[nx][ny] != 0 && dist_F[nx][ny] <= dist_J[cur.first][cur.second] + 1) continue;
            dist_J[nx][ny] = dist_J[cur.first][cur.second] + 1;
            q_J.push({nx, ny});
        }
    }

    std::cout << "IMPOSSIBLE";
}