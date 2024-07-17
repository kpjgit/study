//11050
#include <bits/stdc++.h>

int n, k;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> k;

    int a = 1;
    int b = 1;
    for(int i = 0; i < k; i++) {
        a *= n - i;
        b *= i + 1;
    }
    std::cout << a / b;
}