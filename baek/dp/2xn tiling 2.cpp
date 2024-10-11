//11727
#include <bits/stdc++.h>

int n;

int arr[1000];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;

    arr[0] = 1;
    arr[1] = 3;
    arr[2] = arr[1] + 2 * arr[0]; //첫 공간이 1*2 -> 3-1에 대한 조합, 2*1 or 2*2 -> 3-2에 대한 조합 두번
    for(int i = 2; i < n; i++) arr[i] = (arr[i - 1] + 2 * arr[i - 2]) % 10007;

    std::cout << arr[n - 1];
}