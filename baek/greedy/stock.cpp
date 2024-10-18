//11501
#include <bits/stdc++.h>

int T, N;
int arr[1000000];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> T;
    for(int num = 0; num < T; num++) {
        std::cin >> N;
        for(int i = 0; i < N; i++) std::cin >> arr[i];

        long long ans = 0;
        int mx = arr[N - 1];
        for(int i = N - 2; i >= 0; i--) {
            if(arr[i] > mx) mx = arr[i];
            ans += mx - arr[i];
        }

        std::cout << ans << '\n';
    }
}