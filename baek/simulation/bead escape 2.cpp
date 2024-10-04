//13460
#include <bits/stdc++.h>

int N, M;
char board[10][10];
int dist[10][10][10][10]; //각각 red와 blue의 x, y 인접한 칸은 red, blue가 이동 가능한 조합

int rx0, ry0;
int bx0, by0;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int bfs() {
    std::queue<std::tuple<int, int, int, int>> q;
    q.push({rx0, ry0, bx0, by0});
    dist[rx0][ry0][bx0][by0] = 1;

    while(!q.empty()) {
        int rx, ry, bx, by;
        std::tie(rx, ry, bx, by) = q.front();
        q.pop();

        int cnt = dist[rx][ry][bx][by];
        if(cnt > 10) return -1;
        
        for(int dir = 0; dir < 4; dir++) {
            int nxr = rx;
            int nyr = ry;
            int nxb = bx;
            int nyb = by;

            while(board[nxb + dx[dir]][nyb + dy[dir]] == '.') { //그래프로 보면 rx, ry, bx, by 노드는 배열상 인접한 곳이 아니라 계산이 끝난 nxr, nyr, nxb, nyb (부딪힌 곳)과 연결됨
                nxb += dx[dir];
                nyb += dy[dir];
            }
            if(board[nxb + dx[dir]][nyb + dy[dir]] == 'O') continue;

            while(board[nxr + dx[dir]][nyr + dy[dir]] == '.') {
                nxr += dx[dir];
                nyr += dy[dir];
            }
            if(board[nxr + dx[dir]][nyr + dy[dir]] == 'O') return cnt;

            if(nxr == nxb && nyr == nyb) {
                if(dir == 0) {
                    if(rx > bx) nxb--;
                    else nxr--;
                } else if(dir == 1) {
                    if(ry > by) nyb--;
                    else nyr--;
                } else if(dir == 2) {
                    if(rx < bx) nxb++;
                    else nxr++;
                } else {
                    if(ry < by) nyb++;
                    else nyr++;
                }
            }

            if(dist[nxr][nyr][nxb][nyb] > 0) continue;

            dist[nxr][nyr][nxb][nyb] = cnt + 1;
            q.push({nxr, nyr, nxb, nyb});
        }
    }

    return -1;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> board[i][j];
            if(board[i][j] == 'R') {
                rx0 = i;
                ry0 = j;
                board[i][j] = '.';
            }
            if(board[i][j] == 'B') {
                bx0 = i;
                by0 = j;
                board[i][j] = '.';
            }
        }
    }

    int ans = bfs();
    std::cout << ans;
}