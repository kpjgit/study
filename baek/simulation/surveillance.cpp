//15683
#include <bits/stdc++.h>

int n, m;
int office[10][10];
int vis[10][10];
std::vector<std::pair<int, int>> cams;
int ans = 0;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void check(int x, int y, int dir) {
    dir %= 4;
    while(1) {
        x += dx[dir];
        y += dy[dir];
        if(x < 0 || x >= n || y < 0 || y >= m || vis[x][y] == 6) return;
        if(vis[x][y] != 0) continue;
        vis[x][y] = -1;
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            std::cin >> office[i][j];
            if(office[i][j] > 0 && office[i][j] < 6) {
                cams.push_back({i, j});
            }
            if(office[i][j] == 0) ans++;
        }
    }

    for(int temp = 0; temp < (1 << (2 * cams.size())); temp++) { //각 카메라 방향 정보를 담고 있는 cams 갯수만큼 자릿수의 4진수 or cams * 2만큼 2진수
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                vis[i][j] = office[i][j];
            }
        }

        int brute = temp;
        for(int i = 0; i < cams.size(); i++) {
            int dir = brute % 4;
            brute /= 4;
            int x = cams[i].first;
            int y = cams[i].second;
            if(office[x][y] == 1) {
                check(x, y, dir);
            } else if(office[x][y] == 2) {
                check(x, y, dir);
                check(x, y, dir + 2);
            } else if(office[x][y] == 3) {
                check(x, y, dir);
                check(x, y, dir + 1);
            } else if(office[x][y] == 4) {
                check(x, y, dir);
                check(x, y, dir + 1);
                check(x, y, dir + 2);
            } else { //5
                check(x, y, dir);
                check(x, y, dir + 1);
                check(x, y, dir + 2);
                check(x, y, dir + 3);
            }
        }

        int val = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis[i][j] == 0) {
                    val++;
                }
            }
        }
        ans = std::min(ans, val);
    }

    std::cout << ans;
}