//16985
#include <bits/stdc++.h>

bool arr[4][5][5][5]; //arr[0][][][]일때 0회전 arr[1][][][]일때 1회전
bool maze[5][5][5]; //true일때 이동가능

int dx[] = {1, 0, 0, -1, 0, 0};
int dy[] = {0, 1, 0, 0, -1, 0};
int dz[] = {0, 0, 1, 0, 0, -1};

int bfs() {
    if(maze[0][0][0] == false || maze[4][4][4] == false) return 126;

    int dist[5][5][5] = {};
    std::queue<std::tuple<int, int, int>> q;
    dist[0][0][0] = 1;
    q.push({0, 0, 0});

    while(!q.empty()) {
        int x, y, z;
        std::tie(x, y, z) = q.front();
        q.pop();

        for(int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if(nx < 0 || ny < 0 || nz < 0 || nx >= 5 || ny >= 5 || nz >= 5) continue;
            if(dist[nx][ny][nz] > 0 || maze[nx][ny][nz] == false) continue;

            if(nx == 4 && ny == 4 && nz == 4) return dist[x][y][z];
            
            dist[nx][ny][nz] = dist[x][y][z] + 1;
            q.push({nx, ny, nz});
        }
    }
    
    return 126;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            for(int k = 0; k < 5; k++) std::cin >> arr[0][i][j][k];
        }

        for(int j = 0; j < 5; j++) {
            for(int k = 0; k < 5; k++) arr[1][i][j][k] = arr[0][i][5 - k - 1][j];
        }

        for(int j = 0; j < 5; j++) {
            for(int k = 0; k < 5; k++) arr[2][i][j][k] = arr[1][i][5 - k - 1][j];
        }

        for(int j = 0; j < 5; j++) {
            for(int k = 0; k < 5; k++) arr[3][i][j][k] = arr[2][i][5 - k - 1][j];
        }
    }

    int order[] = {0, 1, 2, 3, 4};
    int ans = 126;
    do {
        for(int num = 0; num < (1 << (2 * 5)); num++) { //4의 5승, 2의 10승
            int brute = num;
            for(int i = 0; i < 5; i++) {
                int dir = brute % 4;
                brute /= 4;

                for(int j = 0; j < 5; j++) {
                    for(int k = 0; k < 5; k++) maze[i][j][k] = arr[dir][order[i]][j][k];
                }
            }

            ans = std::min(ans, bfs());
        }
    } while(std::next_permutation(order, order + 5));
    
    if(ans == 126) std::cout << -1;
    else std::cout << ans;
}