//14503
#include <bits/stdc++.h>

int N, M;
int r, c, d; //0: 북, 1: 동, 2: 남, 3: 서
int room[50][50]; //2일 때 청소함

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1}; //반시계 방향

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M >> r >> c >> d;
    if(d == 1) d = 3;
    else if(d == 3) d = 1;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) std::cin >> room[i][j];
    }

    int ans = 0;
    while(true) {
        bool backward = true;
        if(room[r][c] == 0) {
            ans++;
            room[r][c] = 2;
        }

        for(int i = 0; i < 4; i++) {
            d = (d + 1) % 4;
            int nx = r + dx[d];
            int ny = c + dy[d];

            if(room[nx][ny] == 0) {
                r = nx;
                c = ny;
                backward = false;
                break;
            }
        }

        if(backward) {
            if(room[r - dx[d]][c - dy[d]] == 1) break;

            r -= dx[d];
            c -= dy[d];
        }
    }

    std::cout << ans;
}