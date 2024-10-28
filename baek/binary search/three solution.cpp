//2473
#include <bits/stdc++.h>

int N;
int arr[5000];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) std::cin >> arr[i];
    std::sort(arr, arr + N);

    int ans[3];
    long long prev_sum = 3000000001;
    for(int i = 0; i < N - 2; i++) {
        for(int j = i + 1; j < N - 1; j++) { //n^2logn
            long long sum = arr[i] + arr[j]; //여기까지는 정수 범위
            int idx = std::lower_bound(arr, arr + N, -sum) - arr;

            for(int k = -2; k <= 2; k++) {
                if(idx + k == i || idx + k == j) continue;
                if(idx + k < 0 || idx + k >= N) continue;

                if(std::abs(sum + arr[idx + k]) < prev_sum) {
                    ans[0] = arr[i];
                    ans[1] = arr[j];
                    ans[2] = arr[idx + k];
                    prev_sum = std::abs(sum + arr[idx + k]);
                }
            }
        }
    }

    std::sort(ans, ans + 3);
    for(int i : ans) std::cout << i << ' ';
}