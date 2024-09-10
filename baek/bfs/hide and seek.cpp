//1697
#include <bits/stdc++.h>

int N, K;
int dist[100001];

std::queue<int> q;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> K;
    std::fill(dist, dist + 100001, -1);

    q.push(N);
    dist[N] = 0;
    int todo[3];
    while(dist[K] == -1) {
        int cur = q.front();
        q.pop();
        todo[0] = cur - 1;
        todo[1] = cur + 1;
        todo[2] = cur * 2;

        for(int i : todo) {
            if(i < 0 || i > 100000) continue;
            if(dist[i] != -1) continue;
            dist[i] = dist[cur] + 1;
            q.push(i);
        }
    }

    std::cout << dist[K];
}