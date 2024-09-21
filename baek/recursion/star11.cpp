//2448
#include <bits/stdc++.h>

int N;
char star[1024 * 3][1024 * 3 * 2 - 1];
void func(int n, int x, int y) {
    if(n == 3) {
        star[x][y] = '*';
        star[x + 1][y - 1] = '*';
        star[x + 1][y + 1] = '*';

        for(int i = 0; i < 5; i++) star[x + 2][y - 2 + i] = '*';
        return;
    }

    int nxt = n / 2;
    func(nxt, x, y);
    func(nxt, x + nxt, y - nxt);
    func(nxt, x + nxt, y + nxt);
}
    

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;

    func(N, 0, N - 1);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N * 2 - 1; j++) {
            if(star[i][j] == '*') std::cout << '*';
            else std::cout << ' ';
        }
        std::cout << '\n';
    }
}