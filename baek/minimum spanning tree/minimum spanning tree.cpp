//1197
#include <bits/stdc++.h>

std::vector<int> p(10005, -1);
int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v) {
    u = find(u); v = find(v);
    if(u == v) return 0;
    if(p[u] == p[v]) p[u]--;
    if(p[u] < p[v]) p[v] = u;
    else p[u] = v;
    return 1;
}

int v, e;
std::tuple<int, int, int> edges[100001];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> v >> e;
    for(int i = 0; i < e; i++) {
        int a, b, cost;
        std::cin >> a >> b >> cost;
        edges[i] = {cost, a, b};
    }
    std::sort(edges, edges + e);

    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < e; i++) {
        int a, b, cost;
        std::tie(cost, a, b) = edges[i];
        if(!is_diff_group(a, b)) continue;
        ans += cost;
        cnt++;
        if(cnt == v - 1) break;
    }
    std::cout << ans;
}