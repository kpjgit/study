//2217
#include <bits/stdc++.h>

int N;
int arr[100000];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) std::cin >> arr[i];
    std::sort(arr, arr + N);

    int prev = 0;
    for(int i = N - 1; i >= 0; i--) {
        int num = N - i;
        if(arr[i] * num >= prev) prev = arr[i] * num;
        else break;
    }

    std::cout << prev;
}