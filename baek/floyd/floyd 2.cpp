//11780
#include <bits/stdc++.h>

int n, m;
int table[101][101];
int table_next[101][101];
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
        table_next[a][b] = b;
    }
    for(int i = 1; i <= n; i++) table[i][i] = 0;

    for(int num = 1; num <= n; num++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(table[i][j] > table[i][num] + table[num][j]) {
                    table[i][j] = table[i][num] + table[num][j];
                    table_next[i][j] = table_next[i][num];
                }

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

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(table_next[i][j] == 0 || table_next[i][j] == max) {
                std::cout << "0\n";
                continue;
            }

            std::queue<int> ans;
            int st = i;
            while(st != j) {
                ans.push(st);
                st = table_next[st][j];
            }
            ans.push(j);
            std::cout << ans.size() << ' ';
            while(!ans.empty()) {
                std::cout << ans.front() << ' ';
                ans.pop();
            }
            std::cout << '\n';
        }
    }
}