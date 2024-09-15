//2573
#include <bits/stdc++.h>

int N, M;
int board[300][300];
bool vis[2][300][300]; //vis[0][][]: 방문함 vis[1][][]: 이번 방문에 바다가 됨

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

std::queue<std::pair<int, int>> q;
std::stack<std::pair<int, int>> s;

void bfs(int i, int j) {
    q.push({i, j});
    vis[0][i][j] = true;

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) { //melting ice
            if(board[cur.first][cur.second] == 0) continue;
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) { //범위 밖은 바다 취급
                board[cur.first][cur.second]--;
                continue;
            }

            if(vis[1][nx][ny] == true) continue;

            if(board[nx][ny] == 0) board[cur.first][cur.second]--;
        }

        if(board[cur.first][cur.second] == 0) {
            vis[1][cur.first][cur.second] = true;
            s.push({cur.first, cur.second});
        }

        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(vis[0][nx][ny] == true || board[nx][ny] == 0) continue;
            vis[0][nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> board[i][j];
        }
    }

    int ans = 0;
    int cnt = 0;
    while(true) {
        cnt = 0;
        while(!s.empty()) {
            auto temp = s.top();
            s.pop();
            vis[1][temp.first][temp.second] = false;
        }
        for(int i = 0; i < N; i++) std::fill(vis[0][i], vis[0][i] + M, false);

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(board[i][j] == 0 || vis[0][i][j] == 1) continue;

                bfs(i, j);
                cnt++;
            }
        }

        if(cnt == 0 || cnt > 1) break;
        ans++;
    }

    if(cnt == 0) ans = 0;
    
    std::cout << ans;
}