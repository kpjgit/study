//16398
#include <bits/stdc++.h>

int N, T;
std::vector<std::pair<int, int>> adj_list[1000]; //비용, 연결된 행성

std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
bool vis[1000];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    int cost;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> cost;
            if(i >= j) continue;

            adj_list[i].push_back({cost, j});
            adj_list[j].push_back({cost, i});
        }
    }

    vis[0] = true;
    for(auto& flow : adj_list[0]) pq.push(flow);
    long long ans = 0;
    int cnt = 0;
    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if(vis[cur.second]) continue;

        vis[cur.second] = true;
        cnt++;
        ans += cur.first;
        if(cnt == N - 1) break;

        for(auto& flow : adj_list[cur.second]) if(!vis[flow.second]) pq.push(flow);
    }

    std::cout << ans;
}