#include <bits/stdc++.h>

int N, M;
int arr[8];
bool used[8];

void func(int n, int m, int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) std::cout << arr[i] << ' ';
        std::cout << '\n';
        return;
    }

    for(int i = 1; i <= n; i++) {
        if(used[i] == false) {
            arr[cnt] = i;
            used[i] = true;
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
