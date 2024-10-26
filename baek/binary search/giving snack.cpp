//16401
#include <bits/stdc++.h>

int M, N;
int arr[1000000];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> M >> N;
    for(int i = 0; i < N; i++) std::cin >> arr[i];

    int st = 1;
    int en = *std::max_element(arr, arr + N);
    while(st < en) {
        int mid = (st + en + 1) / 2;

        int cnt = 0;
        for(int i = 0; i < N; i++) cnt += arr[i] / mid;

        if(cnt >= M) st = mid;
        else en = mid - 1;
    }

    int cnt = 0;
    for(int i = 0; i < N; i++) cnt += arr[i] / st;

    if(cnt >= M) std::cout << st;
    else std::cout << 0;
}