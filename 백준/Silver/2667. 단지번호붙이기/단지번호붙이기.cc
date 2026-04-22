#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>

int N;
char board[25][26];

bool vis[25][25];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int bfs(int x, int y) {
    int ret = 1;
    
    std::queue<std::pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = true;
    while(!q.empty()) {
        int x, y;
        std::tie(x, y) = q.front();
        q.pop();
        
        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(board[nx][ny] == '0') continue;
            if(vis[nx][ny]) continue;
            
            ret++;
            vis[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    
    return ret;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> N;
    for(int i = 0; i < N; i++) std::cin >>board[i];
    
    std::vector<int> ans;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(board[i][j] == '0') continue;
            if(vis[i][j]) continue;
            ans.push_back(bfs(i, j));
        }
    }
    
    std::sort(ans.begin(), ans.end());
    std::cout << ans.size() << '\n';
    for(int i : ans) std::cout << i << '\n';
}