//15651
#include <bits/stdc++.h>

int N, M;
int arr[7];

void func(int n, int m, int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) std::cout << arr[i] << ' ';
        std::cout << '\n';
        return;
    }

    for(int i = 1; i <= n; i++) {
        arr[cnt] = i;
        func(n, m, cnt + 1);
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;
    func(N, M, 0);
}