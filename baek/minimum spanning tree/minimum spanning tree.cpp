//1197
#include <bits/stdc++.h>

int V, E;
std::tuple<int, int, int> edge[100000]; //비용, u, v

int par[10001]; //-1로 초기화 하고 부모 노드를 가리킴, 음수일 경우 그 절대값이 트리의 높이

int find(int v) {
    if(par[v] < 0) return v; //끝에 도달하면 루트 반환
    return par[v] = find(par[v]); //경로 압축
}

bool group_check(int u, int v) {
    int group_u = find(u);
    int group_v = find(v);
    if(group_u == group_v) return true; //같은 그룹

    if(par[group_u] == par[group_v]) par[group_u]--; //부모가 같은 경우 어느 한쪽의 트리 높이를 높여 합친다

    if(par[group_u] < par[group_v]) par[group_v] = group_u;
    else par[group_u] = group_v; //높은 트리 아래에 작은 트리를 합친다

    return false;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> V >> E;
    int u, v, cost;
    for(int i = 0; i < E; i++) {
        std::cin >> u >> v >> cost;
        edge[i] = {cost, u, v};
    }
    std::sort(edge, edge + E);

    std::fill(par, par + V + 1, -1);
    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < E; i++) {
        std::tie(cost, u, v) = edge[i];
        if(group_check(u, v)) continue;

        ans += cost;
        cnt++;
        if(cnt == V - 1) break;
    }

    std::cout << ans;
}