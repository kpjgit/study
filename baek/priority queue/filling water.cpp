//2276
#include <bits/stdc++.h>

int N, M;
int arr[300][300];

bool vis[300][300];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> M >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> arr[i][j];
        }
    }

    std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, std::greater<std::tuple<int, int, int>>> pq;
    //높이, x, y

    for(int i = 0; i < M; i++) {
        pq.push({arr[0][i], 0, i});
        vis[0][i] = true;
        pq.push({arr[N - 1][i], N - 1, i});
        vis[N - 1][i] = true;
    }
    for(int i = 1; i < N - 1; i++) {
        pq.push({arr[i][0], i, 0});
        vis[i][0] = true;
        pq.push({arr[i][M - 1], i, M - 1});
        vis[i][M - 1] = true;
    }
    //가장자리의 높이가 담을 수 있는 물의 높이를 결정하므로 가장자리부터 힙에 넣는다
    //이때 물이 넘치지 않도록 가능한 가장 낮은 칸부터 처리해야 하므로 최소 힙을 사용한다


    long long ans = 0; //답은 int 범위 이내지만 계산 중간에 int 범위를 벗어날 수 있다
    while(!pq.empty()) {
        int h, x, y;
        std::tie(h, x, y) = pq.top();
        pq.pop();

        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(vis[nx][ny]) continue;

            vis[nx][ny] = true;

            if(h > arr[nx][ny]) {
                ans += h - arr[nx][ny];
                pq.push({h, nx, ny});
            } else {
                pq.push({arr[nx][ny], nx, ny});
            }
        }
    }

    std::cout << ans;
}