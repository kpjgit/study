//2110
#include <bits/stdc++.h>

int N, C;
int arr[200000];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> C;
    for(int i = 0; i < N; i++) std::cin >> arr[i];
    std::sort(arr, arr + N);

    int st = 1;
    int en = arr[N - 1];
    while(st < en) {
        int mid = (st + en + 1) / 2; //거리
        
        int cur = 0;
        int cnt = 0;
        while(cur < N) {
            cur = std::lower_bound(arr + cur, arr + N, arr[cur] + mid) - arr; //cur~N 사이의 mid 이상의 첫번째 위치
            cnt++;
        }

        if(cnt >= C) st = mid;
        else en = mid - 1;
    }

    std::cout << st;
}