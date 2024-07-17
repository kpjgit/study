//1654 pharametric
#include <bits/stdc++.h>

int k, n;
int arr[10001];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> k >> n;
    for(int i = 0; i < k; i++) std::cin >> arr[i];
    std::sort(arr, arr + k);

    long long st = 1;
    long long en = arr[0];
    while(st < en) {
        long long mid = (st + en + 1) / 2;
        int num = 0;
        for(int i = 0; i < k; i++) {
            num += arr[i] / mid;
        }

        if(num >= n) {
            st = mid;
        } else {
            en = mid - 1;
        }
    }

    std::cout << st;
}