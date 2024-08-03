//11404
#include <bits/stdc++.h>

int n, m;
int table[101][101];
int max = 0x3f3f3f3f;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        std::fill(table[i], table[i] + n + 1, max);
    }
    for(int i = 0; i < m; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        table[a][b] = std::min(table[a][b], c);
    }
    for(int i = 1; i <= n; i++) table[i][i] = 0;

    for(int num = 1; num <= n; num++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                table[i][j] = std::min(table[i][j], table[i][num] + table[num][j]);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(table[i][j] == max) std::cout << "0 ";
            else std::cout << table[i][j] << ' ';
        }
        std::cout << '\n';
    }
}