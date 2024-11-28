//11562
#include <bits/stdc++.h>

int n, m, k;
int arr[251][251]; //st에서 en에 도달하기 위해 일방통행이면서 역행해야 하는 최소 길의 수

const int inf = 251;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        std::fill(arr[i] + 1, arr[i] + n + 1, inf);
        arr[i][i] = 0;
    }
    
    int u, v;
    bool b;
    for(int i = 0; i < m; i++) {
        std::cin >> u >> v >> b;

        arr[u][v] = 0;
        arr[v][u] = !b;
    }

    for(int route = 1; route <= n; route++) {
        for(int st = 1; st <= n; st++) {
            for(int en = 1; en <= n; en++) {
                arr[st][en] = std::min(arr[st][en], arr[st][route] + arr[route][en]);
            }
        }
    }

    std::cin >> k;
    for(int i = 0; i < k; i++) {
        std::cin >> u >> v;
        std::cout << arr[u][v] << '\n';
    }
}