//2447
#include <bits/stdc++.h>

int N;
char star[6570][6570];

void func(int n, int x, int y) {
    int nxt = n / 3;

    if(n == 3) {
        for(int i = x; i < x + n; i++) {
            for(int j = y; j < y + n; j++) {
                if(i == x + nxt && j == y + nxt) star[i][j] = ' ';
                else star[i][j] = '*';
            }
        }
        return;
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i == 1 && j == 1) {
                for(int ii = x + nxt; ii < x + 2 * nxt; ii++) {
                    for(int jj = y + nxt; jj < y + 2 * nxt; jj++) {
                        star[ii][jj] = ' ';
                    }
                }
                continue;
            } else {
                func(nxt, x + i * nxt, y + j * nxt);
            }
        }
    }

}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    func(N, 0, 0);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) std::cout << star[i][j];
        std::cout << '\n';
    }
}