//11047
#include <bits/stdc++.h>

int n, k;
int arr[11];
int index;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> k;
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
        if(arr[i] <= k) index = i;
    }

    int ans = 0;
    int temp = 0;
    while(1) {
        if(temp + arr[index] <= k) {
            temp += arr[index];
            ans++;
            if(temp == k) break;
        } else index--;
    }
    /*
    for(int i = n - 1; i >= 0; i--) {
        ans = k / arr[i];
        k %= arr[i];
    }
    */

    std::cout << ans;
}