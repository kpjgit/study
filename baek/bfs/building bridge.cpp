//2146
#include <bits/stdc++.h>

int N;
int board[100][100];
bool vis[100][100];
int dist[100][100];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

std::queue<std::pair<int, int>> q;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) std::cin >> board[i][j];
    }

    int index_island = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(vis[i][j] == true || board[i][j] == 0) continue;
            
            vis[i][j] = true;
            q.push({i, j});
            while(!q.empty()) {
                auto cur = q.front();
                q.pop();
                board[cur.first][cur.second] = index_island;
                
                for(int i = 0; i < 4; i++) {
                    int nx = cur.first + dx[i];
                    int ny = cur.second + dy[i];

                    if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                    if(vis[nx][ny] == true || board[nx][ny] == 0) continue;
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }

            index_island++;
        }
    }

    int ans = 210000000;
    for(int i = 0; i < N; i++) std::fill(dist[i], dist[i] + N, -1);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(board[i][j] != 0) {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(board[nx][ny] == board[cur.first][cur.second]) continue;
            if(board[nx][ny] != 0) {
                ans = std::min(ans, dist[nx][ny] + dist[cur.first][cur.second]);
            } else {
                board[nx][ny] = board[cur.first][cur.second];
                dist[nx][ny] = dist[cur.first][cur.second] + 1;
                q.push({nx, ny});
            }
        }
    }

    std::cout << ans;
}