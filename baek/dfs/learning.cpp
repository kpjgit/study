//-1
#include <bits/stdc++.h>

int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} }; 

int vis[502][502];
int n = 7, m = 10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

std::stack<std::pair<int, int>> s;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vis[0][0] = 1;
    s.push({0, 0});
    while(!s.empty()) {
        auto cur = s.top();
        s.pop();
        std::cout << '(' << cur.first << ", " << cur.second << ") -> ";
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(vis[nx][ny] != 0 || board[nx][ny] != 1) continue;
            vis[nx][ny] = 1;
            s.push({nx, ny});
        }
    }
}