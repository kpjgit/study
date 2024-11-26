//11404
#include <bits/stdc++.h>

int n, m;
int table[101][101];

const int inf = 10000001;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    for(int i = 1; i <= n; i++) {std::fill(
        table[i] + 1, table[i] + n + 1, inf);
        table[i][i] = 0;
    }

    int u, v, cost;
    for(int i = 0; i < m; i++) {
        std::cin >> u >> v >> cost;
        table[u][v] = std::min(table[u][v], cost);
    }

    for(int route = 1; route <= n; route++) {
        for(int st = 1; st <= n; st++) {
            for(int en = 1; en <= n; en++) {
                table[st][en] = std::min(table[st][en], table[st][route] + table[route][en]);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(table[i][j] == inf) std::cout << "0 ";
            else std::cout << table[i][j] << ' ';
        }
        std::cout << '\n';
    }
}