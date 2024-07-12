//11659
#include <bits/stdc++.h>

int n, m;
int arr[100001];
int precal[100001];
int index = 1;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        std::cin >> arr[i];
    }

    for(int i = 1; i <= n; i++) {
        precal[i] = arr[i] + precal[i - 1];
    }

    int st, en;
    for(int i = 0; i < m; i++) {
        std::cin >> st >> en;
        std::cout << precal[en] - precal[st - 1] << '\n';
    }
}