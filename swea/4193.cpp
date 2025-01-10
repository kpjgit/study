#include <bits/stdc++.h>

int T;
int N;
int A, B;
int C, D;
int board[15][15];

int vis[15][15];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs() {
    std::queue<std::tuple<int, int, int>> q; //x, y, time
    q.push({A, B, 0});
    vis[A][B] = 0;
   
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        int x, y, t;
        std::tie(x, y, t) = cur;
       
        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
           
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(board[nx][ny] == 1 || vis[nx][ny] == true) continue;
            if(board[nx][ny] == 2) {
                if(t % 3 == 2) { //2, 5, 8 ... 일때 소용돌이 없음
                    q.push({nx, ny, t + 1});
                    vis[nx][ny] = true;
                } else {
                    q.push({x, y, t + 1}); //소용돌이가 끝나기를 기다림
                }
            } else {
                if(nx == C && ny == D) return t + 1;
                
                q.push({nx, ny, t + 1});
                vis[nx][ny] = true;
            }
        }
    }
    
    return -1; //여기까지 왔으면 도달 불가
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
   
    std::cin >> T;
    for(int num = 1; num <= T; num++) {
        std::cin >> N;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                std::cin >> board[i][j];
            }
           
            std::fill(vis[i], vis[i] + N, false);
        }
        std::cin >> A >> B >> C >> D;
       
        int ans = bfs();
        std::cout << '#' << num << ' ' << ans << '\n';
    }
}