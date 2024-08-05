//11779
#include <bits/stdc++.h>

std::vector<std::pair<int, int>> adj[1001]; //비용, 번호
std::priority_queue<std::pair<int, int>> pq;
int max = 0x3f3f3f3f;
int table[1001];
int pre[1001];
int n, m, st, en;

void dijkstra_better(int st) {
    std::fill(table, table + n + 1, max);
    
    table[st] = 0;
    pre[st] = 0;
    pq.push({0, st});

    while(!pq.empty()) {
        std::pair<int, int> cur = pq.top();
        pq.pop();

        if(cur.first != table[cur.second]) continue;

        for(auto next : adj[cur.second]) {
            if(table[next.second] > table[cur.second] + next.first) {
                table[next.second] = table[cur.second] + next.first;
                pre[next.second] = cur.second;
                pq.push({table[next.second], next.second});
            }
        }
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int st, en, cost;
        std::cin >> st >> en >> cost;
        adj[st].push_back({cost, en});
    }
    std::cin >> st >> en;

    dijkstra_better(st);

    std::cout << table[en] << '\n';
    std::stack<int> path;
    int cur = en;
    while(cur != st) {
        path.push(cur);
        cur = pre[cur];
    }
    path.push(cur);
    std::cout << path.size() <<'\n';
    while(!path.empty()) {
        std::cout << path.top() << ' ';
        path.pop();
    }
}