//2217
#include <bits/stdc++.h>

int n;
int arr[10001];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    std::sort(arr, arr + n);

    int prev = 0;
    int num = 1;
    for(int i = n - 1; i >= 0; i--) {
        if(arr[i] * num >= prev) {
            prev = arr[i] * num;
            num++;
        } else break;
    }

    std::cout << prev;
}