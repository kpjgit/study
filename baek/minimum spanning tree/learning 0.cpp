//-1 primm
#include <bits/stdc++.h>

int main(void) {
    int v, e;
    std::vector<std::pair<int, int>> adj[10001];
    bool check[10001];
    int cnt = 0;
    std::priority_queue<std::tuple<int, int, int>, 
        std::vector<std::tuple<int, int, int>>, 
        std::greater<std::tuple<int, int, int>>> pq;

    check[1] = 1;
    for(auto e : adj[1]) {
        pq.push({e.first, 1, e.second});
    }

    while(cnt < v - 1) {
        int cost, a, b;
        std::tie(cost, a, b) = pq.top();
        pq.pop();
        if(check[b]) break;
        std::cout << cost << ' ' << a << ' ' << b << '\n';
        check[b] = true;
        cnt++;
        for(auto e : adj[b]) {
            if(!check[e.second]) pq.push({e.first, b, e.second});
        }
    }
}