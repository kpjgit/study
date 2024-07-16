//1026
#include <bits/stdc++.h>

int n;
int a[51];
int b[51];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    for(int i = 0; i < n; i++) std::cin >> a[i];
    for(int i = 0; i < n; i++) std::cin >> b[i];
    std::sort(a, a + n);
    std::sort(b, b + n);

    int ans = 0;
    for(int i = 0; i < n; i++) ans += a[i] * b[n - 1 - i];
    std::cout << ans;
}