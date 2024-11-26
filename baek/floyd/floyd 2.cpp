//11780
#include <bits/stdc++.h>

int n, m;
int table[101][101];
int table_next[101][101];

const int inf = 10000001;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        std::fill(table[i] + 1, table[i] + n + 1, inf);
        table[i][i] = 0;
    }

    int u, v, cost;
    for(int i = 0; i < m; i++) {
        std::cin >> u >> v >> cost;
        table[u][v] = std::min(table[u][v], cost);
        table_next[u][v] = v;
    }

    for(int route = 1; route <= n; route++) {
        for(int st = 1; st <= n; st++) {
            for(int en = 1; en <= n; en++) {
                if(table[st][en] > table[st][route] + table[route][en]) {
                    table[st][en] = table[st][route] + table[route][en];
                    table_next[st][en] = table_next[st][route];
                }
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

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(table_next[i][j] == 0) {
                std::cout << "0\n";
                continue;
            }

            std::vector<int> ans;
            int prev = i;
            ans.push_back(prev);
            while(prev != j) {
                prev = table_next[prev][j];
                ans.push_back(prev);
            }

            std::cout << ans.size() << ' ';
            for(int i : ans) std::cout << i << ' ';
            std::cout << '\n';
        }
    }
}