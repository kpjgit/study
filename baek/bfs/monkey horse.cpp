//1600
#include <bits/stdc++.h>

int K;
int H, W;
int board[200][200];
int dist[31][200][200];

int dx_h[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy_h[] = {1, 2, 2, 1, -1, -2, -2, -1};

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

std::queue<std::tuple<int, int, int>> q;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> K >> W >> H;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            std::cin >> board[i][j];
        }
    }

    for(int i = 0; i <= K; i++) {
        for(int j = 0; j < H; j++) {
            std::fill(dist[i][j], dist[i][j] + W, -1);
        }
    }

    dist[0][0][0] = 0;
    q.push(std::make_tuple(0, 0, 0));
    while(!q.empty()) {
        int x, y, num;
        std::tie(x, y, num) = q.front();
        q.pop();

        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if(nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
            if(board[nx][ny] == 1 || dist[num][nx][ny] != -1) continue;
            dist[num][nx][ny] = dist[num][x][y] + 1;
            q.push(std::make_tuple(nx, ny, num));
        }

        if(num < K) {
            for(int dir = 0; dir < 8; dir++) {
                int nx = x + dx_h[dir];
                int ny = y + dy_h[dir];

                if(nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
                if(board[nx][ny] == 1 || dist[num + 1][nx][ny] != -1) continue;
                dist[num + 1][nx][ny] = dist[num][x][y] + 1;
                q.push(std::make_tuple(nx, ny, num + 1));
            }
        }
    }

    int ans = 30 * 200 * 200;
    for(int i = 0; i <= K; i++) {
        if(dist[i][H - 1][W - 1] > -1) {
            ans = std::min(ans, dist[i][H - 1][W - 1]);
        }
    }

    if(ans != 30 * 200 * 200) std::cout << ans;
    else std::cout << -1;
}