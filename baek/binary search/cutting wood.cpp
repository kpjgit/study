//2805
#include <bits/stdc++.h>

int N, M;
int arr[1000000];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;
    for(int i = 0; i < N; i++) std::cin >> arr[i];

    int st = 0;
    int en = *std::max_element(arr, arr + N);
    while(st < en) {
        int mid = (st + en + 1) / 2;

        long long cnt = 0;
        for(int i = 0; i < N; i++) if(arr[i] > mid) cnt += arr[i] - mid;

        if(cnt >= M) st = mid;
        else en = mid - 1;
    }

    std::cout << st;
}