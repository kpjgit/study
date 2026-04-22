#include <iostream>
#include <tuple>
#include <queue>
#include <vector>

int N, M;
//각 방에 있는 전구 스위치
std::vector<std::pair<int, int>> switch_board[100][100];

bool light[100][100];
bool vis[100][100];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> N >> M;
    
    int x, y, a, b;
    for(int i = 0; i < M; i++) {
        std::cin >> x >> y >> a >> b;
        x--; y--; a--; b--;
        switch_board[x][y].push_back({a, b});
    }
    
    int ans = 1;
    std::queue<std::pair<int, int>> q;
    light[0][0] = true;
    q.push({0, 0});
    while(!q.empty()) {
        int x, y;
        std::tie(x, y) = q.front();
        q.pop();
        
        if(vis[x][y]) continue;
        vis[x][y] = true;
        
        for(auto& i : switch_board[x][y]) {
            int light_x = i.first;
            int light_y = i.second;
            
            if(light[light_x][light_y]) continue;
            light[light_x][light_y] = true;
            ans++;
            
            //이미 방문하여 경로 끊겼는데 켜졌을 경우 검사
            bool connected = false;
            for(int dir = 0; dir < 4; dir++) {
                int nx = light_x + dx[dir];
                int ny = light_y + dy[dir];
                
                if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                if(vis[nx][ny]) {
                    connected = true;
                    break;
                }
            }
            
            if(connected) q.push({light_x, light_y});
        }
        
        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(!light[nx][ny]) continue;
            if(vis[nx][ny]) continue;
            
            q.push({nx, ny});
        }
    }
    
    std::cout << ans;
}