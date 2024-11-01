//20166
#include <bits/stdc++.h>

int N, M, K;
char arr[10][10];

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M >> K;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) std::cin >> arr[i][j];
    }
    
    std::unordered_map<std::string, int> um;
    for(int i = 0; i < N; i++) { //dfs도 상관 없음, 살짝 더 빠를 수 있음
        for(int j = 0; j < M; j++) {
            std::queue<std::tuple<int, int, std::string>> q;
            q.push({i, j, std::string(1, arr[i][j])});

            while(!q.empty()) {
                int x, y;
                std::string str;
                std::tie(x, y, str) = q.front();
                q.pop();
                um[str]++;

                if(str.size() == 5) continue;

                for(int dir = 0; dir < 8; dir++) {
                    int nx = (x + dx[dir] + N) % N;
                    int ny = (y + dy[dir] + M) % M;
                    q.push({nx, ny, str + arr[nx][ny]});
                }
            }
        }
    }

    std::string s;
    for(int i = 0; i < K; i++) {
        std::cin >> s;
        std::cout << um[s] << '\n';
    }
}