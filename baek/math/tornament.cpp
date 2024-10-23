//1057
#include <bits/stdc++.h>

int N, K, L;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> K >> L;

    int l, r;
    if(K > L) {
        r = K;
        l = L;
    } else {
        r = L;
        l = K;
    }

    int ans = 0;
    while(N > 0) {
        ans++;
        int gap = r - l;

        if(r % 2 == 0 && gap == 1) {
            std::cout << ans;
            return 0;
        }

        r = (r + 1) / 2;
        l = (l + 1) / 2;

        N /= 2;
    }

    std::cout << -1;
}