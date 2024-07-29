//-1 kruskal
#include <bits/stdc++.h>

bool is_diff_group(int a, int b); //union find 

int main(void) {
    int v, e;
    std::tuple<int, int, int> edges[100005]; //비용, 정점1, 정점2

    std::sort(edges, edges + e);
    int cnt = 0;
    for(int i = 0; i < e; i++) {
        int cost, a, b;
        std::tie(cost, a, b) = edges[i];
        if(is_diff_group(a, b)) continue;
        std::cout << cost << ' ' << a << ' ' << b;
        cnt++;
        if(cnt == v - 1) break;
    }

}