//9613
#include <bits/stdc++.h>

int t, n;
int arr[100];

int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b % a, a);
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> t;
    for(int num = 0; num < t; num++) {
        std::cin >> n;
        for(int i = 0; i < n; i++) std::cin >> arr[i];

        long long ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) ans += gcd(arr[i], arr[j]);
        }
        std::cout << ans << '\n';
    }
}