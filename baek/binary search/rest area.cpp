//1477
#include <bits/stdc++.h>

int N, M, L;
int arr[51];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M >> L;
    for(int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    arr[N] = L;
    std::sort(arr, arr + N);

    int st = 1;
    int en = L;
    while(st < en) { //구간을 자르는 길이
        int mid = (st + en) / 2;

        int cnt = 0;
        int prev = 0;
        for(int i = 0; i <= N; i++) {
            int dist = arr[i] - prev;

            if(dist >= mid) {
                if(dist % mid != 0) {
                    cnt += dist / mid;
                } else { //나누어 떨어지면 -1을 해야함
                    cnt += dist / mid - 1;
                }
            }

            prev = arr[i];
        }

        if(cnt > M) st = mid + 1;
        else en = mid;
    }

    std::cout << st;
}