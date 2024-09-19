//13549 0-1 bfs
#include <bits/stdc++.h>

int dist[200002];
int N, K;

std::deque<int> dq;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::fill(dist, dist + 200002, -1);
    std::cin >> N >> K;
    dq.push_back(N);
    dist[N] = 0;

    int nx[2];
    while(!dq.empty()) {
        int cur = dq.front();
        dq.pop_front();

        nx[0] = cur - 1;
        nx[1] = cur + 1;

        if(cur * 2 < 200000 && dist[cur * 2] == -1) {
            dist[cur * 2] = dist[cur];
            dq.push_front(cur * 2);
        }

        for(int dir : nx) {
            if(dir < 0 || dir >= 200000 || dist[dir] != -1) continue;
            dist[dir] = dist[cur] + 1;
            dq.push_back(dir);
        }
    }

    std::cout << dist[K];
}