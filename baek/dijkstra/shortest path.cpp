//1753
#include <bits/stdc++.h>

std::vector<std::pair<int, int>> adj[20001]; //비용, 번호
std::priority_queue<std::pair<int, int>> pq;
int max = 0x3f3f3f3f;
int table[20001];
int v, e, k;

void dijkstra_better(int st) {
    std::fill(table, table + v + 1, max);
    
    table[st] = 0;
    pq.push({0, st});

    while(!pq.empty()) {
        std::pair<int, int> cur = pq.top();
        pq.pop();

        if(cur.first != table[cur.second]) continue;

        for(auto next : adj[cur.second]) {
            if(table[next.second] > table[cur.second] + next.first) {
                table[next.second] = table[cur.second] + next.first;
                pq.push({table[next.second], next.second});
            }
        }
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> v >> e >> k;
    for(int i = 0; i < e; i++) {
        int st, en, cost;
        std::cin >> st >> en >> cost;
        adj[st].push_back({cost, en});
    }

    dijkstra_better(k);
    for(int i = 1; i <= v; i++) {
        if(table[i] == max) std::cout << "INF\n";
        else std::cout << table[i] << '\n';
    }
}