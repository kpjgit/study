//6064 연립합동방정식
#include <bits/stdc++.h>

int T, M, N, x, y; //x, y는 M, N으로 나눈 나머지

int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b % a, a);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int func(int M, int N, int x, int y) {
    if(x == M) x = 0;
    if(y == N) y = 0;

    int l = lcm(M, N);
    for(int i = x; i <= l; i += M) {
        if(i == 0) continue;
        if(i % N == y) return i;
    }

    return -1;
}

int main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> T;
    for(int num = 0; num < T; num++) {
        std::cin >> M >> N >> x >> y;
        std::cout << func(M, N, x, y) <<'\n';
    }
}