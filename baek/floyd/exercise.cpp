//1956
#include <bits/stdc++.h>

int V, E; //st, en일때 일방 통행이므로 st에서 en으로 가는 경로가 있고 en에서 st로 가능 경로가 있으면 사이클
int arr[401][401];

const int inf = 4000001;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> V >> E;
    for(int i = 1; i <= V; i++) {
        std::fill(arr[i] + 1, arr[i] + V + 1, inf);
        arr[i][i] = 0;
    }

    int u, v, cost;
    for(int i = 0; i < E; i++) {
        std::cin >> u >> v >> cost;
        if(arr[u][v] > cost) arr[u][v] = cost;
    }

    for(int route = 1; route <= V; route++) {
        for(int st = 1; st <= V; st++) {
            for(int en = 1; en <= V; en++) {
                arr[st][en] = std::min(arr[st][en], arr[st][route] + arr[route][en]);
            }
        }
    }

    int ans = inf * 2;
    for(int en = 1; en <= V; en++) {
        for(int st = 1; st <= V; st++) {
            if(arr[st][en] == inf || arr[en][st] == inf || st == en) continue;
            ans = std::min(ans, arr[st][en] + arr[en][st]);
        }
    }

    if(ans == inf * 2) std::cout << -1;
    else std::cout << ans;
}