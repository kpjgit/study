//15650
#include <bits/stdc++.h>

int N, M;

int arr[9];
bool used[9];

void func(int n, int m, int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) std::cout << arr[i] << ' ';
        std::cout << '\n';
        return;
    }

    int i = 1;
    if(cnt != 0) i = arr[cnt - 1] + 1;
    for(; i <= n; i++) {
        if(used[i] == false) {
            used[i] = true;
            arr[cnt] = i;
            func(n, m, cnt + 1);
            used[i] = false;
        }
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;
    func(N, M, 0);
}