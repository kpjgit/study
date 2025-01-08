#include <bits/stdc++.h>

int T;
int N;
char arr[300][300];

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool chk_adj(int x, int y) {
    for(int dir = 0; dir < 8; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        if(arr[nx][ny] == '*') return true;
    }

    return false;
}

void bfs(int x, int y) {
    std::queue<std::pair<int, int>> q;
    q.push({x, y});
    arr[x][y] = 'v';

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();

        bool adj_mine = false;
        for(int dir = 0; dir < 8; dir++) { //인근에 지뢰가 있는지 확인
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(arr[nx][ny] == '*') {
                adj_mine = true;
                break;
            }
        }
        if(adj_mine) continue;

        for(int dir = 0; dir < 8; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(arr[nx][ny] == 'v') continue; //이미 방문한 경우

            q.push({nx, ny});
            arr[nx][ny] = 'v';
        }
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> T;
    for(int num = 1; num <= T; num++) {
        std::cin >> N;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                std::cin >> arr[i][j];
            }
        }

        int ans = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(arr[i][j] != '.') continue;
                if(chk_adj(i, j)) continue; //주변에 폭탄 있음

                ans++;
                bfs(i, j);
            }
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(arr[i][j] == '.') ans++;
            }
        }

        std::cout << '#' << num << ' ' << ans << '\n';
    }
}