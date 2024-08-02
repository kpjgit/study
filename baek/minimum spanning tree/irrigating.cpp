//1368
#include <bits/stdc++.h>

int n;
int v, e;
std::vector<std::pair<int, int>> adj[301];
bool check[301];
int cnt = 0;
int ans = 0;
std::priority_queue<std::tuple<int, int, int>, 
    std::vector<std::tuple<int, int, int>>, 
    std::greater<std::tuple<int, int, int>>> pq;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    v = n + 1;
    for(int i = 0; i < n; i++) {
        int w;
        std::cin >> w;
        adj[i].push_back({w, n});
        adj[n].push_back({w, i});
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int w;
            std::cin >> w;
            if(i == j) continue;
            adj[i].push_back({w, j});
        }
    }

    check[0] = true;
    for(auto next : adj[0]) {
        pq.push({next.first, 0, next.second});
    }

    while(cnt < v - 1) {
        int cost, a, b;
        std::tie(cost, a, b) = pq.top();
        pq.pop();
        if(check[b]) continue;;
        check[b] = true;
        cnt++;
        ans += cost;
        for(auto next : adj[b]) {
            if(!check[next.second]) pq.push({next.first, b, next.second});
        }
    }

    std::cout << ans;
}