//11559
#include <bits/stdc++.h>

char field[12][6];
int vis[12][6] = {}; //2일 때 puyo, 1일 때 bfs는 했지만 puyo 아님

std::vector<std::pair<int, int>> v;
std::queue<std::pair<int, int>> q;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int height[6] = {};

bool bfs(int x, int y) {
    const char color = field[x][y];
    vis[x][y] = 2;
    q.push({x, y});
    v.push_back({x, y});
    int num = 1;

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
            if(vis[nx][ny] > 0 || field[nx][ny] != color) continue;
            vis[nx][ny] = 2;
            q.push({nx, ny});
            v.push_back({nx, ny});
            num++;
        }
    }

    int curx, cury;
    if(num < 4) {
        for(int i = 0; i < num; i++) {
            std::tie(curx, cury) = v[v.size() - i - 1];
            vis[curx][cury]--;
        }
        return false;
    } else return true;
}

void do_puyo() {
    int x, y;
    while(!v.empty()) {
        std::tie(x, y) = v.back();
        v.pop_back();
        if(vis[x][y] == 2) field[x][y] = '.';
        vis[x][y] = false;
    }

    for(int j = 5; j >= 0; j--) {
        int idx = -1;
        int height_temp = 0;
        for(int i = 11; i >= 0; i--) {
            if(i < 12 - height[j]) break;

            if(field[i][j] == '.') height_temp++;

            if(idx == -1 && field[i][j] == '.') idx = i;

            if(idx != -1 && field[i][j] != '.') {
                field[idx][j] = field[i][j];
                field[i][j] = '.';
                idx--;
            }
        }
        height[j] -= height_temp;
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for(int i = 0; i < 12; i++) {
        for(int j = 0; j < 6; j++) {
            std::cin >> field[i][j];
            if(field[i][j] != '.') height[j]++;
        }
    }

    int chain = 0;
    while(true) {
        int puyo = 0;
        for(int i = 11; i >= 0; i--) {
            int dots = 0; //6일 경우 모두 탐색됨
            for(int j = 5; j >= 0; j--) {
                if(field[i][j] == '.') dots++;
                else if(vis[i][j] == 0) puyo += bfs(i, j);
            }

            if(dots == 6) break;
        }

        if(puyo > 0) {
            do_puyo();
            chain++;
        } else break;
    }

    std::cout << chain;
}