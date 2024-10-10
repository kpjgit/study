//9095
#include <bits/stdc++.h>

int n;
int T;
int arr[12];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    arr[1] = 1;
    arr[2] = 2; //arr[1] + 1
    arr[3] = 4; //arr[1] + arr[2] + 1

    for(int i = 4; i <= 11; i++) {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    }

    std::cin >> T;
    for(int i = 0; i < T; i++) {
        std::cin >> n;
        std::cout << arr[n] << '\n';
    }
}