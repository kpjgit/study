//2748
#include <bits/stdc++.h>

int N;
long long fibo[91];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    fibo[0] = 0;
    fibo[1] = 1;

    for(int i = 2; i <= N; i++) fibo[i] = fibo[i - 1] + fibo[i - 2];
    std::cout << fibo[N];
}