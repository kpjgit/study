//1149
#include <bits/stdc++.h>

int N;
int cost[1000][3];

int min_cost[1000][3]; //[i][j] i번 집을 j로 칠할때의 누적 최소값

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) std::cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

    min_cost[0][0] = cost[0][0];
    min_cost[0][1] = cost[0][1];
    min_cost[0][2] = cost[0][2];

    for(int i = 1; i < N; i++) {
        min_cost[i][0] = cost[i][0] + std::min(min_cost[i - 1][1], min_cost[i - 1][2]);
        min_cost[i][1] = cost[i][1] + std::min(min_cost[i - 1][0], min_cost[i - 1][2]);
        min_cost[i][2] = cost[i][2] + std::min(min_cost[i - 1][1], min_cost[i - 1][0]);
    }

    int ans;
    ans = std::min(min_cost[N - 1][0], min_cost[N - 1][1]);
    ans = std::min(ans, min_cost[N - 1][2]);
    std::cout << ans;
}