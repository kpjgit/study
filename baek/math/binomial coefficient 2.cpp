//11051
#include <bits/stdc++.h>

int N, K;
int arr[1001][1001]; //arr[i][j] iCj의 값

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for(int i = 1; i <= 1000; i++) {
        arr[i][0] = 1;
        arr[i][i] = 1;
        for(int j = 1; j < i; j++) {
            arr[i][j] = (arr[i - 1][j] + arr[i - 1][j - 1] % 10007);
        }
    }

    std::cin >> N >> K;
    std::cout << arr[N][K];
}