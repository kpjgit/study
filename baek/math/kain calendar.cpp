//6064 연립합동방정식
#include <bits/stdc++.h>

int k;
int m, n, x, y;

int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b % a, a);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int func() {
    int mnlcm = lcm(m, n);
    if(x == m) x = 0;
    if(y == n) y = 0;

    for(int i = x; i <= mnlcm; i += m) {
        if(i == 0) continue;
        if(i % n == y) return i;
    }

    return -1;
}

int main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> k;

    for(int i = 0; i < k; i++) {
        std::cin >> m >> n >> x >> y;
        std::cout << func() << '\n';
    }


}