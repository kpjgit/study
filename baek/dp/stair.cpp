//2579
#include <bits/stdc++.h>

int n;
int stairs[301];
int arr[301][2];//arr[n][0]은 arr[n - 1][]를 밟지 않음, arr[n][1]은 arr[n-1][0]을 밟음

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> stairs[i];
    }

    if(n == 1) {
        std::cout << stairs[0];
        return 0;
    }

    arr[0][0] = stairs[0];
    arr[1][0] = stairs[1];
    arr[0][1] = 0;
    arr[1][1] = stairs[0] + stairs[1];
    
    for(int i = 2; i < n; i++) {
        arr[i][0] = std::max(arr[i - 2][0], arr[i - 2][1]) + stairs[i];
        arr[i][1] = arr[i - 1][0] + stairs[i];
    }

    std::cout << std::max(arr[n - 1][0], arr[n - 1][1]);
}