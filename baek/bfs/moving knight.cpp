//7562
#include <bits/stdc++.h>

int n, l;
int dist[300][300];

int dx[] = {-2, -1, 1, 2, 2, 1, -2, -1};
int dy[] = {1, 2, 2, 1, -1, -2, -1, -2};

std::queue<std::pair<int, int>> q;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;

    int stx, sty;
    int enx, eny;
    for(int num = 0; num < n; num++) {
        std::cin >> l;
        std::cin >> stx >> sty >> enx >> eny;
        for(int i = 0; i < l; i++) {
            std::fill(dist[i], dist[i] + l, 0);
        }

        if(stx == enx && sty == eny) {
            std::cout << 0 << '\n';
            continue;
        }

        q.push({stx, sty});
        dist[stx][sty] = 1;
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();

            for(int dir = 0; dir < 8; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if(nx < 0 || ny < 0 || nx >= l || ny >= l) continue;
                if(dist[nx][ny] > 0) continue;
                if(nx == enx && ny == eny) {
                    std::cout << dist[cur.first][cur.second] << '\n';
                    while(!q.empty()) q.pop();
                    break;
                }
                q.push({nx, ny});
                dist[nx][ny] = dist[cur.first][cur.second] + 1;
            }
        }
    }
}