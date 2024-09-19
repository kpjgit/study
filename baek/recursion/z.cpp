//1074
#include <bits/stdc++.h>

int N, r, c;

int Z(int x, int y, int n) {
    if(n == 0) return 0;
    int size = 1 << (n - 1);

    if(x < size && y < size) return Z(x, y, n - 1);
    if(x < size && y >= size) return size * size + Z(x, y - size, n - 1);
    if(x >= size && y < size) return 2 * size * size + Z(x - size, y, n - 1);
    return 3 * size * size + Z(x - size, y - size, n - 1);
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> r >> c;
    std::cout << Z(r, c, N);
}