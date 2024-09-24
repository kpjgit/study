//1941
#include <bits/stdc++.h>

char arr[5][5];
bool pat[5][5];
int ans = 0;
std::queue<std::pair<int, int>> q;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) std::cin >> arr[i][j];
    }

    std::fill(pat[0] + 7, pat[0] + 25, true);
    do {
        int num_s = 0, cnt = 0;
        bool vis[5][5] = {};

        bool escape = false;
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                if(pat[i][j] == false) {
                    vis[i][j] = true;
                    q.push({i, j});
                    escape = true;
                    break;
                }
            }
            if(escape) break;
        }

        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            cnt++;
            if(arr[cur.first][cur.second] == 'S') num_s++;

            for(int i = 0; i < 4; i++) {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                
                if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
                if(pat[nx][ny] == true || vis[nx][ny] == true) continue;

                q.push({nx, ny});
                vis[nx][ny] = true;
            }
        }

        if(cnt == 7 && num_s >= 4) ans++;

    } while(std::next_permutation(pat[0], pat[0] + 25));

    std::cout << ans;
}