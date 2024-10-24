//3066
#include <bits/stdc++.h>

int N;
int first;

int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b % a, a);
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    std::cin >> first;
    int rest;
    for(int i = 0; i < N - 1; i++) {
        std::cin >> rest;

        int d = gcd(first, rest);
        std::cout << first / d << '/' << rest / d << '\n';
    }
}