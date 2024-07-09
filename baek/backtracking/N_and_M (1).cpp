//15649
#include <bits/stdc++.h>

int n, m;
int arr[10];
bool used[10];

void func(int k) {
    if(k == m) {
        for(int i = 0; i < m; i++) {
            std::cout << arr[i] << ' ';
        }
        std::cout << '\n';
        return;
    }

    for(int i = 1; i <= n; i++) {
        if(!used[i]) {
            arr[k] = i;
            used[i] = 1;
            func(k + 1);
            used[i] = 0;
        }
    }

}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    func(0);
}
