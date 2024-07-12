//1149
#include <bits/stdc++.h>

int n;
int cost[1000][3];
int mincost[1000][3];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    mincost[0][0] = cost[0][0];
    mincost[0][1] = cost[0][1];
    mincost[0][2] = cost[0][2];

    for(int i = 1; i < n; i++) {
        mincost[i][0] = cost[i][0] + std::min(mincost[i - 1][1], mincost[i - 1][2]);
        mincost[i][1] = cost[i][1] + std::min(mincost[i - 1][0], mincost[i - 1][2]);
        mincost[i][2] = cost[i][2] + std::min(mincost[i - 1][1], mincost[i - 1][0]);
    }

    int ans = std::min(mincost[n - 1][0], mincost[n - 1][1]);
    ans = std::min(ans, mincost[n - 1][2]);

    std::cout << ans;
    //std::cout << *std::min_element(mincost[n - 1], mincost[n - 1] + 3);
    //std::cout << std::min({mincost[n - 1][0], mincost[n - 1][1], mincost[n - 1][2]});
}