//2178
#include <bits/stdc++.h>

int N, M;
bool board[101][101];
int dist[101][101];

std::queue<std::pair<int, int>> q;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};


int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;

    std::string str;
    for(int i = 0; i < N; i++) {
        std::cin >> str;
        for(int j = 0; j < M; j++) {
            board[i][j] = str[j] - '0';
        }
    }

    q.push({0, 0});
    dist[0][0] = 1; //dist를 -1로 초기화하고 dist[0][0] = 0로 시작하는 방법도 있음
    while(!q.empty()) {
        std::pair<int, int> cur = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(dist[nx][ny] > 0 || board[nx][ny] == 0) continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }

    std::cout << dist[N - 1][M - 1];
}