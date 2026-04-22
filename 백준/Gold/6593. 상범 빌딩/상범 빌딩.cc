#include <iostream>
#include <queue>
#include <tuple>

int L, R, C;
char building[30][30][30];

int dist[30][30][30];

int dx[] = {-1, 0, 1, 0, 0, 0};
int dy[] = {0, 1, 0, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

int bfs(int sx, int sy, int sz) {
    std::queue<std::tuple<int, int, int>> q;
    q.push({sx, sy, sz});
    dist[sx][sy][sz] = 0;
    while(!q.empty()) {
        int x, y, z;
        std::tie(x, y, z) = q.front();
        q.pop();
        
        for(int dir = 0; dir < 6; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z + dz[dir];
            
            if(nx < 0 || ny < 0 || nz < 0 || nx >= R || ny >= C || nz >= L) continue;
            if(building[nx][ny][nz] == '#') continue;
            if(dist[nx][ny][nz] != -1) continue;
            
            dist[nx][ny][nz] = dist[x][y][z] + 1;
            if(building[nx][ny][nz] == 'E') return dist[nx][ny][nz];
            q.push({nx, ny, nz});
        }
    }
    
    return -1;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    while(true) {
        std::cin >> L >> R >> C;
        if(L == 0) break;
        
        int x, y, z;
        for(int i = L - 1; i >= 0; i--) {
            for(int j = 0; j < R; j++) {
                for(int k = 0; k < C; k++) {
                    std::cin >> building[j][k][i];
                    dist[j][k][i] = -1;
                    
                    if(building[j][k][i] == 'S') {
                        z = i;
                        x = j;
                        y = k;
                    }
                }
            }
        }
        
        int ans = bfs(x, y, z);
        if(ans == -1) std::cout << "Trapped!\n";
        else std::cout << "Escaped in "<< ans << " minute(s).\n";
    }
}