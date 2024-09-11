//2206
#include <bits/stdc++.h>

int N, M;
bool board[1001][1001];
int dist[1001][1001][2];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

std::queue<std::tuple<int, int, bool>> q; //bool은 벽을 부쉈는지

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;
    char val;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> val;
            board[i][j] = val - '0';
        }
    }

    dist[0][0][0] = 1;
    q.push(std::make_tuple(0, 0, false));
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();

        for(int dir = 0; dir < 4; dir++) {
            int nx = std::get<0>(cur) + dx[dir];
            int ny = std::get<1>(cur) + dy[dir];
            bool chk = std::get<2>(cur);

            int cost = dist[std::get<0>(cur)][std::get<1>(cur)][chk] + 1;

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(dist[nx][ny][chk] > 0) continue;
            if(board[nx][ny] == 1) {
                if(chk == false) {
                    chk = true;
                } else {
                    continue;
                }
            }

            q.push(std::make_tuple(nx, ny, chk));
            dist[nx][ny][chk] = cost;
        }
    }

    int ans = -1;
    if(dist[N - 1][M - 1][0] > 0) ans = dist[N - 1][M - 1][0];
    if(dist[N - 1][M - 1][1] > 0) ans = dist[N - 1][M - 1][1];
    std::cout << ans;
}