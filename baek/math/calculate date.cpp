//1476
#include <bits/stdc++.h>

int E, S, M; //15 28 19

int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b % a, a);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> E >> S >> M;
    E--;
    S--;
    M--;

    int i = E;
    while(i % 28 != S) i += 15;

    int l = lcm(15, 28);
    while(i % 19 != M) i += l;
    
    std::cout << i + 1;
}