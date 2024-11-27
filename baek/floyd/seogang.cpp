//14938
#include <bits/stdc++.h>

int n, m, r; //시작점에서부터 m 이하의 노드 값의 합 -> 시작점에서 나머지 노드로 가는 최단거리 문제
int arr[101][101];
int point[101];

const int inf = 1501;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m >> r;
    for(int i = 1; i <= n; i++) std::cin >> point[i];

    for(int i = 1; i <= n; i++) {
        std::fill(arr[i] + 1, arr[i] + n + 1, inf);
        arr[i][i] = 0;
    }

    int u, v, cost;
    for(int i = 0; i < r; i++) {
        std::cin >> u >> v >> cost;
        if(arr[u][v] > cost) {
            arr[u][v] = cost;
            arr[v][u] = cost;
        }
    }

    for(int route = 1; route <= n; route++) {
        for(int st = 1; st <= n; st++) {
            for(int en = 1; en <= n; en++) {
                arr[st][en] = std::min(arr[st][en], arr[st][route] + arr[route][en]);
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int sum = 0;
        for(int j = 1; j <= n; j++) {
            if(arr[i][j] <= m) sum += point[j];
        }

        ans = std::max(ans, sum);
    }

    std::cout << ans;
}