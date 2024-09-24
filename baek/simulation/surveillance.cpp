//15683
#include <bits/stdc++.h>

int N, M;
std::vector<std::pair<int, int>> cams;
int office[8][8];
int vis[8][8];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int ans = 64;

void func(int x, int y, int dir, int& temp) {
    dir %= 4;
    while(true) {
        x += dx[dir];
        y += dy[dir];
        if(x < 0 || y < 0 || x >= N || y >= M || office[x][y] == 6) return;
        if(vis[x][y] == 0) {
            vis[x][y] = -1;
            temp++;
        }
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;
    int temp;
    int walls = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> temp;
            if(temp > 0) {
                office[i][j] = temp;
                if(temp < 6) cams.push_back({i, j});
                else walls++;
            }
        }
    }

    for(int rot = 0; rot < (1 << (cams.size() * 2)); rot++) { //4진법으로 카메라의 방향을 저장
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++){
                vis[i][j] = office[i][j];
            }
        }

        int brute = rot;
        int temp = 0;
        for(int i = 0; i < cams.size(); i++) {
            int dir = brute % 4;
            brute /= 4;
            int x, y;
            std::tie(x, y) = cams[i];
            
            if(office[x][y] == 1) {
                func(x, y, dir, temp);
            } else if(office[x][y] == 2) {
                func(x, y, dir, temp);
                func(x, y, dir + 2, temp);
            } else if(office[x][y] == 3) {
                func(x, y, dir, temp);
                func(x, y, dir + 1, temp);
            } else if(office[x][y] == 4) {
                func(x, y, dir, temp);
                func(x, y, dir + 1, temp);
                func(x, y, dir + 2, temp);
            } else if(office[x][y] == 5) {
                func(x, y, dir, temp);
                func(x, y, dir + 1, temp);
                func(x, y, dir + 2, temp);
                func(x, y, dir + 3, temp);
            }
        }
        int next = N * M - temp - cams.size() - walls;
        ans = std::min(ans, next);
    }

    std::cout << ans;
}