//3151
#include <bits/stdc++.h>

int N;
int arr[10000];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) std::cin >> arr[i];
    std::sort(arr, arr + N);

    long long ans = 0;
    for(int i = 0; i < N - 2; i++) {
        for(int j = i + 1; j < N - 1; j++) {
            int sum = arr[i] + arr[j];

            ans += std::upper_bound(arr + j + 1, arr + N, -sum) - std::lower_bound(arr + j + 1, arr + N, -sum);
        }
    }

    std::cout << ans;
}