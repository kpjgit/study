//1719
#include <bits/stdc++.h>

int n, m;
int arr[201][201];
int next[201][201];

const int inf = 200001;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        std::fill(arr[i] + 1, arr[i] + n + 1, inf);
        arr[i][i] = 0;
    }

    int u, v, cost;
    for(int i = 0; i < m; i++) {
        std::cin >> u >> v >> cost;
        arr[u][v] = cost;
        arr[v][u] = cost;
        next[u][v] = v;
        next[v][u] = u;
    }

    for(int route = 1; route <= n; route++) {
        for(int st = 1; st <= n; st++) {
            for(int en = 1; en <= n; en++) {
                if(arr[st][en] > arr[st][route] + arr[route][en]) {
                    arr[st][en] = arr[st][route] + arr[route][en];
                    next[st][en] = next[st][route];
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) std::cout << "- ";
            else std::cout << next[i][j] << ' ';
        }
        std::cout << '\n'; 
    }
}