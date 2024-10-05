//14890
#include <bits/stdc++.h>

int N, L;
int map[100][100];

int ans = 0;
void func(int x, int y, int dx, int dy) {
    int height = map[x][y];
    int length = 1;
    bool build = false;
    int nx = x;
    int ny = y;

    for(int i = 1; i < N; i++) {
        nx += dx;
        ny += dy;

        if(map[nx][ny] == height) length++;

        if(std::abs(map[nx][ny] - height) > 1) return;
        
        if(map[nx][ny] > height) {
            if(build == true) return;
            if(length < L) return;
            
            length = 1;
            height = map[nx][ny];
        }

        if(map[nx][ny] < height) {
            if(build == true) return;
            build = true;
            height = map[nx][ny];
            length = 1;
        }

        if(build == true && length == L) {
            build = false;
            length = 0;
        }
    }

    if(build == true) return;

    ans++;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> L;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) std::cin >> map[i][j];
    }

    for(int i = 0; i < N; i++) {
        func(i, 0, 0, 1);
        func(0, i, 1, 0);
    }

    std::cout << ans;
}