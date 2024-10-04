//14500
#include <bits/stdc++.h>

int N, M;
int paper[500][500];

int di[2][4] = {{0, 0, 0, 0}, {0, 1, 2, 3}};
int dl[2][4] = {{0, 0, -1, -2}, {0, 1, 0, 0}};
int d[2][4] = {{0, 0, 1, 1}, {0, 1, 0, 1}};
int dt[2][4] = {{0, 0, 1, 0}, {0, 1, 1, 2}};
int dz[2][4] = {{0, -1, 0, 1}, {0, 0, 1, 1}};

int sign[2][8] = {{1, 1, -1, -1, 1, 1, -1, -1}, {1, -1, -1, 1, -1, 1, 1, -1}}; //정방향 회전 0~270, 대칭 후 회전 0~270, 홀수일때 x, y 바꿔서

int ans = 0;

bool out_of_range(int nx, int ny) {
    if(nx < 0 || ny < 0 || nx >= N || ny >= M) return true;
    return false;
}

void func(int x, int y) {
    int temp = 0;
    int nx, ny;

    for(int i = 0; i < 4; i++) {
        nx = x + d[0][i];
        ny = y + d[1][i];
        if(out_of_range(nx, ny)) break;
        
        temp += paper[nx][ny];
        if(i == 3) ans = std::max(ans, temp);
    } //사각형

    for(int dir = 0; dir < 2; dir++) {
        temp = 0;

        if(dir % 2 == 0) {
            for(int i = 0; i < 4; i++) {
                nx = x + sign[0][dir] * di[0][i];
                ny = y + sign[1][dir] * di[1][i];
                if(out_of_range(nx, ny)) break;

                temp += paper[nx][ny];
                if(i == 3) ans = std::max(ans, temp);
            }
        } else {
            for(int i = 0; i < 4; i++) {
                nx = x + sign[0][dir] * di[1][i];
                ny = y + sign[1][dir] * di[0][i];
                if(out_of_range(nx, ny)) break;

                temp += paper[nx][ny];
                if(i == 3) ans = std::max(ans, temp);
            }
        }
    } //직선

    for(int dir = 0; dir < 8; dir++) {
        temp = 0;

        if(dir % 2 == 0) {
            for(int i = 0; i < 4; i++) {
                nx = x + sign[0][dir] * dl[0][i];
                ny = y + sign[1][dir] * dl[1][i];
                if(out_of_range(nx, ny)) break;

                temp += paper[nx][ny];
                if(i == 3) ans = std::max(ans, temp);
            }
        } else {
            for(int i = 0; i < 4; i++) {
                nx = x + sign[0][dir] * dl[1][i];
                ny = y + sign[1][dir] * dl[0][i];
                if(out_of_range(nx, ny)) break;

                temp += paper[nx][ny];
                if(i == 3) ans = std::max(ans, temp);
            }
        }
    } //L

    for(int dir = 0; dir < 8; dir++) {
        temp = 0;

        if(dir % 2 == 0) {
            for(int i = 0; i < 4; i++) {
                nx = x + sign[0][dir] * dt[0][i];
                ny = y + sign[1][dir] * dt[1][i];
                if(out_of_range(nx, ny)) break;

                temp += paper[nx][ny];
                if(i == 3) ans = std::max(ans, temp);
            }
        } else {
            for(int i = 0; i < 4; i++) {
                nx = x + sign[0][dir] * dt[1][i];
                ny = y + sign[1][dir] * dt[0][i];
                if(out_of_range(nx, ny)) break;

                temp += paper[nx][ny];
                if(i == 3) ans = std::max(ans, temp);
            }
        }
    } //T

    for(int dir = 0; dir < 2; dir++) {
        temp = 0;

        if(dir % 2 == 0) {
            for(int i = 0; i < 4; i++) {
                nx = x + sign[0][dir] * dz[0][i];
                ny = y + sign[1][dir] * dz[1][i];
                if(out_of_range(nx, ny)) break;

                temp += paper[nx][ny];
                if(i == 3) ans = std::max(ans, temp);
            }
        } else {
            for(int i = 0; i < 4; i++) {
                nx = x + sign[0][dir] * dz[1][i];
                ny = y + sign[1][dir] * dz[0][i];
                if(out_of_range(nx, ny)) break;

                temp += paper[nx][ny];
                if(i == 3) ans = std::max(ans, temp);
            }
        }
    } //Z

    for(int dir = 4; dir < 6; dir++) {
        temp = 0;

        if(dir % 2 == 0) {
            for(int i = 0; i < 4; i++) {
                nx = x + sign[0][dir] * dz[0][i];
                ny = y + sign[1][dir] * dz[1][i];
                if(out_of_range(nx, ny)) break;

                temp += paper[nx][ny];
                if(i == 3) ans = std::max(ans, temp);
            }
        } else {
            for(int i = 0; i < 4; i++) {
                nx = x + sign[0][dir] * dz[1][i];
                ny = y + sign[1][dir] * dz[0][i];
                if(out_of_range(nx, ny)) break;

                temp += paper[nx][ny];
                if(i == 3) ans = std::max(ans, temp);
            }
        }
    } //Z 대칭
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) std::cin >> paper[i][j];
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) func(i, j);
    }

    std::cout << ans;
}