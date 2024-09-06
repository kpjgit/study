//1926
#include <bits/stdc++.h>

int n, m;

bool board[501][501];
bool vis[501][501];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            std::cin >> board[i][j];
        }
    }

    std::queue<std::pair<int, int>> q;
    int ans_max = 0;
    int ans_num = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 1 && vis[i][j] == 0) {
                q.push({i, j});
                vis[i][j] = 1;
                int temp = 0;
                ans_num++;

                while(!q.empty()) {
                    std::pair<int, int> cur = q.front();
                    q.pop();
                    temp++;

                    for(int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if(nx < 0 || ny < 0 || nx >= 6 || ny >= 5) continue;
                        if(board[nx][ny] == 0 || vis[nx][ny] == 1) continue;
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }

                ans_max = std::max(ans_max, temp);
            }
        }
    }

    std::cout << ans_num << '\n' << ans_max;
}