//1676
#include <bits/stdc++.h>

int N;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    int five = 0;
    for(int i = 5; i <= N; i *= 5) {
        five += N / i;
    }

    std::cout << five;
}