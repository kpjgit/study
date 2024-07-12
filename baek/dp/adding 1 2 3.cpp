//9095
#include <bits/stdc++.h>

int n;
int t;
int arr[15];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;

    for(int i = 4; i < 11; i++) {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    }

    std::cin >> t;
    for(int i = 0; i < t; i++) {
        std::cin >> n;
        std::cout << arr[n] << '\n';
    }
}