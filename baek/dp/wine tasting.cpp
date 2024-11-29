//2156
#include <bits/stdc++.h>

int n;
int arr[10000];

int table[10000][3]; //table[i][j], i번째 와인까지 도달했는데 연속으로 마신 와인이 j개일때 최대값

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    for(int i = 0; i < n; i++) std::cin >> arr[i];

    if(n == 1) {
        std::cout << arr[0];
        return 0;
    }

    table[0][0] = 0;
    table[0][1] = arr[0];
    table[1][0] = std::max(table[0][0], table[0][1]);
    table[1][1] = table[0][0] + arr[1];
    table[1][2] = table[0][1] + arr[1];
    for(int i = 2; i < n; i++) {
        table[i][0] = std::max({table[i - 1][0], table[i - 1][1], table[i - 1][2]});
        table[i][1] = table[i - 1][0] + arr[i];
        table[i][2] = table[i - 1][1] + arr[i];
    }

    std::cout << std::max({table[n - 1][0], table[n - 1][1], table[n - 1][2]});
}