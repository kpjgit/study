#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

int N;
int board[20][20];
int xs, ys;
int size = 2;
int size_cnt = 0;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int func() {
    int dist[20][20];
    for(int i = 0; i < N; i++) std::fill(dist[i], dist[i] + N, -1);
    
    int ret = 42000;
    int xc;
    int yc;
    
    std::queue<std::pair<int, int>> q;
    dist[xs][ys] = 0;
    q.push({xs, ys});
    while(!q.empty()) {
        int x, y;
        std::tie(x, y) = q.front();
        q.pop();
        
        if(dist[x][y] >= ret) continue;
        
        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(board[nx][ny] > size) continue;
            if(dist[nx][ny] != -1) continue;
            
            dist[nx][ny] = dist[x][y] + 1;
            
            if(board[nx][ny] != 0 && board[nx][ny] < size) {
                int temp = dist[nx][ny];
                if(temp < ret || (temp == ret && (nx < xc || (nx == xc && ny < yc)))) {
                    ret = temp;
                    xc = nx;
                    yc = ny;
                }
            }
            
            q.push({nx, ny});
        }
    }
    
    if(ret == 42000) return -1;
    
    size_cnt++;
    if(size_cnt == size) {
        size++;
        size_cnt = 0;
    }
    xs = xc;
    ys = yc;
    board[xc][yc] = 0;
    return ret;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> board[i][j];
            if(board[i][j] == 9) {
                xs = i;
                ys = j;
                board[i][j] = 0;
            }
        }
    }
    
    int ans = 0;
    int temp = func();
    while(temp != -1) {
        ans += temp;
        temp = func();
    }

    std::cout << ans;
}