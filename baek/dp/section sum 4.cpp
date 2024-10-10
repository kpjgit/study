//11659
#include <bits/stdc++.h>

int N, M;

int arr[100000];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;
    std::cin >> arr[0];
    int temp;
    for(int i = 1; i < N; i++) {
        std::cin >> temp;
        arr[i] = arr[i - 1] + temp;
    }

    int st, en;
    for(int i = 0; i < M; i++) {
        std::cin >> st >> en;
        st--;
        en--;

        if(st == 0) std::cout << arr[en] << '\n';
        else std::cout << arr[en] - arr[st - 1] << '\n';
    }
}