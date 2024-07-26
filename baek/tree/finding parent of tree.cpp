//11725
#include <bits/stdc++.h>

int n;
std::vector<int> adj[100001];
int par[100001];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int st, en;
        std::cin >> st >> en;
        adj[st].push_back(en);
        adj[en].push_back(st);
    }

    std::queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int next : adj[cur]) {
            if(next == par[cur]) continue;
            q.push(next);
            par[next] = cur;
        }
    }

    for(int i = 2; i <= n; i++) std::cout << par[i] <<'\n';
}