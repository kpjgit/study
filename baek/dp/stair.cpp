//2579
#include <bits/stdc++.h>

int N;
int stair[301]; //음수 인덱스를 참조하는걸 막기 위함

int arr[301][2]; //arr[i][j] i번째 계단을 밟았을 때의 최대값, i를 포함해 j개의 연속된 계단을 밟음

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 1; i <= N; i++) std::cin >> stair[i];

    if(N == 1) {
        std::cout << stair[1];
        return 0;
    }

    arr[1][0] = stair[1];
    arr[2][0] = stair[2];
    arr[2][1] = arr[1][0] + stair[2];

    for(int i = 3; i <= N; i++) {
        arr[i][0] = std::max(arr[i - 2][0], arr[i - 2][1]) + stair[i];
        arr[i][1] = arr[i - 1][0] + stair[i];
    }

    std::cout << std::max(arr[N][0], arr[N][1]);
}