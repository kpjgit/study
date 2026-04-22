#include <bits/stdc++.h>

int R, C;
char arr[20][20];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool vis['Z' + 1];
int func(int x, int y) {
    int ret = 1;
    
    int mx = 0;
    for(int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
        if(vis[arr[nx][ny]]) continue;
        
        vis[arr[nx][ny]] = true;
        mx = std::max(mx, func(nx, ny));
        vis[arr[nx][ny]] = false;
    }
    ret += mx;
    
    return ret;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> R >> C;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            std::cin >> arr[i][j];
        }
    }
    
    vis[arr[0][0]] = true;
    std::cout << func(0, 0);
}