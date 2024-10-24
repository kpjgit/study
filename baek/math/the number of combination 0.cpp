//2004
#include <bits/stdc++.h>

long long n, m;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    long long nm = n - m;
    long long five = 0;
    long long two = 0;

    for(long long i = 5; i <= n; i *= 5) {
        five += n / i;
        five -= m / i;
        five -= nm / i;
    }
    for(long long i = 2; i <= n; i *= 2) { //팩토리얼과 다르게 항상 2가 많다고 보장할 수 없다
        two += n / i;
        two -= m / i;
        two -= nm / i;
    }

    std::cout << std::min(five, two);
}