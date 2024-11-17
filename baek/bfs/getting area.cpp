//2583
#include <bits/stdc++.h>

int N, M, K;
bool board[100][100];

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> M >> N >> K;
    int xl, yl, xr, yr;
    for(int i = 0; i < K; i++) {
        std::cin >> xl >> yl >> xr >> yr;

        for(int i = yl; i < yr; i++) {
            for(int j = xl; j < xr; j++) {
                board[i][j] = true;
            }
        }
    }

    std::vector<int> ans;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(board[i][j]) continue;

            int cnt = 0;
            std::queue<std::pair<int, int>> q;
            board[i][j] = true;
            q.push({i, j});

            while(!q.empty()) {
                auto cur = q.front();
                q.pop();
                cnt++;

                for(int dir = 0; dir < 4; dir++) {
                    int ny = cur.first + dy[dir];
                    int nx = cur.second + dx[dir];

                    if(ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
                    if(board[ny][nx]) continue;

                    board[ny][nx] = true;
                    q.push({ny, nx});
                }
            }

            ans.push_back(cnt);
        }
    }

    std::sort(ans.begin(), ans.end());
    std::cout << ans.size() << '\n';
    for(int i : ans) std::cout << i << ' ';
}