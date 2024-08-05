//-1
#include <bits/stdc++.h>

std::vector<std::pair<int, int>> adj[10001]; //비용, 번호
std::priority_queue<std::pair<int, int>,
                    std::vector<std::pair<int, int>>, 
                    std::greater<std::pair<int, int>>> pq;
int max = 0x3f3f3f3f;
int table[10001];
int v = 10;

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

}