//-1
#include <bits/stdc++.h>

int board[512][512] =
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}}; //1은 이동가능, 0은 막힘
bool vis[512][512];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n = 7, m = 10;

int main(void) {
    std::queue<std::pair<int, int>> q;
    vis[0][0] = 1;
    q.push({0, 0});

    while(!q.empty()) {
        std::pair<int, int> cur = q.front();
        q.pop();

        std::cout << '(' << cur.first << ", " << cur.second << ") -> ";
        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= 7 || ny >= 10) continue;
            if(vis[nx][ny] == 1 || board[nx][ny] == 0) continue;
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
}