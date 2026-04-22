#include <iostream>
#include <algorithm>

int N;
int board[100][100];

int p[100 * 100];
bool init[100 * 100];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v) {
    u = find(u);
    v = find(v);
    
    if(u == v) return false;
    
    if(p[u] > p[v]) std::swap(u, v);
    if(p[u] == p[v]) p[u]--;
    p[v] = u;
    
    return true;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int height = 0;
    std::cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> board[i][j];
            height = std::max(height, board[i][j]);
        }
    }
    
    int ans = 0;
    int group = 0;
    std::fill(p, p + N * N, -1);
    for(int h = height - 1; h >= 0; h--) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                int u = N * i + j;
                
                if(board[i][j] > h && !init[u]) {
                    group++;
                    init[u] = true;
                }
                
                if(!init[u]) continue;
                
                for(int dir = 0; dir < 4; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    int v = N * nx + ny;
                    
                    if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                    if(board[nx][ny] <= h) continue;
                    if(!init[v]) continue;
                    
                    if(uni(u, v)) {
                        group--;
                    }
                }
            }
        }
        
        ans = std::max(ans, group);
    }
    
    std::cout << ans;
}