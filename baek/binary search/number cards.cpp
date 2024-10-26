//10815
#include <bits/stdc++.h>

int N, M;
int arr[500000];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) std::cin >> arr[i];
    std::sort(arr, arr + N);

    std::cin >> M;
    for(int num = 0; num < M; num++) {
        int val;
        std::cin >> val;
        
        std::cout << std::binary_search(arr, arr + N, val) << ' ';
    }
}