//2579
#include <bits/stdc++.h>

int n;
int stairs[301];
int arr[301];//밟지 않은 계단 합의 최솟값

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int sum = 0;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> stairs[i];
        sum += stairs[i];
    }

    if(n == 1) {
        std::cout << stairs[0];
        return 0;
    } else if(n == 2) {
        std::cout << stairs[0] + stairs[1];
        return 0;
    }

    arr[0] = stairs[0];
    arr[1] = stairs[1];
    arr[2] = stairs[2];
    
    for(int i = 3; i < n - 1; i++) {
        arr[i] = stairs[i] + std::min(arr[i - 2], arr[i - 3]);
    }

    std::cout << sum - std::min(arr[n - 2], arr[n - 3]);
}