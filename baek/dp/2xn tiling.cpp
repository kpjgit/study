//11726
#include <bits/stdc++.h>

int n;
int arr[1001];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;

    arr[0] = 1;
    arr[1] = 2;

    for(int i = 2; i < n; i++) arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;

    std::cout << arr[n - 1];
}