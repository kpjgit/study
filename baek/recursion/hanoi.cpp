//11729
#include <bits/stdc++.h>

int N;

void hanoi(int a, int b, int n) { //n개를 a에서 b로 옮긴다
    if(n == 1) {
        std::cout << a << ' ' << b << '\n';
        return;
    }

    hanoi(a, 6 - a - b , n - 1);
    std::cout << a << ' ' << b << '\n';
    hanoi(6 - a - b, b, n -1);
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;

    int ans = 1;
    ans = ans << N;
    ans--;
    std::cout << ans << '\n';
    hanoi(1, 3, N);
}