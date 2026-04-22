#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

int n, m;
int board[1000][1000];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int dist[1000][1000];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int x, y;
    std::cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            std::cin >> board[i][j];
            if(board[i][j] == 2) {
                x = i;
                y = j;
            }
        }
    }
    
    for(int i = 0; i < n; i++) std::fill(dist[i], dist[i] + m, -1);
    
    std::queue<std::pair<int, int>> q;
    q.push({x, y});
    dist[x][y] = 0;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(dist[nx][ny] != -1) continue;
            if(board[nx][ny] == 0) continue;
            
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] != 0) std::cout << dist[i][j];
            else std::cout << 0;
            std::cout << ' ';
        }
        std::cout << '\n';
    }
}