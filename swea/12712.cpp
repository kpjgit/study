#include <bits/stdc++.h>

int T;
int N, M;
int arr[15][15];

int dx_p[4] = {-1, 0, 1, 0};
int dy_p[4] = {0, 1, 0, -1};
int dx_x[4] = {-1, 1, 1, -1};
int dy_x[4] = {1, 1, -1, -1};

int func(int x, int y) {
    int sum0 = arr[x][y];
    int sum1 = arr[x][y];
    
    for(int dir = 0; dir < 4; dir++) {
        int nx = x;
        int ny = y;
        for(int i = 1; i < M; i++) {
            nx += dx_p[dir];
            ny += dy_p[dir];

            if(nx < 0 || ny < 0 || nx >= N || ny >= N) break;
            sum0 += arr[nx][ny];            
        }
    }

    for(int dir = 0; dir < 4; dir++) {
        int nx = x;
        int ny = y;
        for(int i = 1; i < M; i++) {
            nx += dx_x[dir];
            ny += dy_x[dir];

            if(nx < 0 || ny < 0 || nx >= N || ny >= N) break;
            sum1 += arr[nx][ny];            
        }
    }

    return std::max(sum0, sum1);
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> T;
    for(int num = 1; num <= T; num++) {
        std::cin >> N >> M;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                std::cin >> arr[i][j];
            }
        }

        int ans = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                ans = std::max(ans, func(i, j));
            }
        }

        std::cout << "#" << num << ' ' << ans << '\n';
    }
}