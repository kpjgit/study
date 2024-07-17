//11051
#include <bits/stdc++.h>

int n, k;
int comb[1001][1001];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for(int i = 1; i <= 1000; i++) {
        comb[i][0] = comb[i][i] = 1;
        for(int j = 1; j < i; j++) {
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1] % 10007);
        }
    }

    std::cin >> n >> k;
    std::cout << comb[n][k];
}