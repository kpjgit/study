//1629
#include <bits/stdc++.h>

long long A, B, C;

long long pow(long long a, long long b, long long m) {
    if(b == 1) return a % m;
    long long val = pow(a, b / 2, m);
    val = val * val % m;
    if(b % 2 == 0) return val;
    return val * a % m;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> A >> B >> C;
    std::cout << pow(A, B, C);
}