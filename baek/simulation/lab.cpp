//14502
#include <bits/stdc++.h>

int N, M;
int lab[8][8];
bool vis[8][8];

std::vector<std::pair<int, int>> virus;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int ans = 0;

void bfs() {
    std::queue<std::pair<int, int>> q;
    for(auto i : virus) {
        q.push(i);
        vis[i.first][i.second] = true;
    }

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(vis[nx][ny] == true || lab[nx][ny] > 0) continue;

            q.push({nx, ny});
            vis[nx][ny] = true;
        }
    }
}

void func(int cnt, int row = 0, int col = 0) {
    if(cnt == 3) {
        bfs();
        int temp = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(vis[i][j] == false && lab[i][j] == 0) temp++; 
            }
        }
        ans = std::max(ans, temp);
        
        for(int i = 0; i < N; i++) {
            std::fill(vis[i], vis[i] + M, false);
        }
        return;
    }

    for(int i = row; i < N; i++) {
        int col_st = (i == row) ? col : 0;
        for(int j = col_st; j < M; j++) {
            if(lab[i][j] > 0) continue;
            lab[i][j] = 1;
            func(cnt + 1, i, j + 1);
            lab[i][j] = 0;
        }
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> lab[i][j];
            if(lab[i][j] == 2) virus.push_back({i, j});
        }
    }

    func(0);
    std::cout << ans;
}