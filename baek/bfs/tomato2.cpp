//7569
#include <bits/stdc++.h>

int N, M, H;

int box[101][101][101];
int dist[101][101][101];

int dx[] = {1, 0, 0, -1, 0, 0};
int dy[] = {0, 1, 0, 0, -1, 0};
int dz[] = {0, 0, 1, 0, 0, -1};

std::queue<std::tuple<int, int, int>> q;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> M >> N >> H;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                std::cin >> box[i][j][k];

                if(box[i][j][k] == 1) {
                    q.push(std::make_tuple(i, j, k));
                    dist[i][j][k] = 0;
                } else if(box[i][j][k] == 0) dist[i][j][k] = -1;
            }
        }
    }

    while(!q.empty()) {
        std::tuple<int, int, int> cur = q.front();
        q.pop();

        for(int i = 0; i < 6; i++) {
            int nz = std::get<0>(cur) + dz[i];
            int nx = std::get<1>(cur) + dx[i];
            int ny = std::get<2>(cur) + dy[i];

            if(nx < 0 || ny < 0 || nz < 0|| nx >= N || ny >= M || nz >= H) continue;
            if(dist[nz][nx][ny] >= 0 || box[nz][nx][ny] == -1) continue;

            q.push(std::make_tuple(nz, nx, ny));
            dist[nz][nx][ny] = dist[std::get<0>(cur)][std::get<1>(cur)][std::get<2>(cur)] + 1;
        }
    }

    int ans = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                if(dist[i][j][k] > ans) ans = dist[i][j][k];
                if(dist[i][j][k] == -1) {
                    std::cout << -1;
                    return 0;
                }
            }
        }
    }

    std::cout << ans;
}