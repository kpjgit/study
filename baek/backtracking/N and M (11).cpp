//15665
#include <bits/stdc++.h>

int N, M;
int arr_n[8];
int arr[8];

void func(int n, int m, int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) std::cout << arr[i] << ' ';
        std::cout << '\n';
        return;
    }

    int prev = 0;
    for(int i = 0; i < n; i++) {
        if(prev == arr_n[i]) continue;
        prev = arr_n[i];
        arr[cnt] = arr_n[i];
        func(n, m, cnt + 1);
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;
    for(int i = 0; i < N; i++) std::cin >> arr_n[i];
    std::sort(arr_n, arr_n + N);
    func(N, M, 0);
}