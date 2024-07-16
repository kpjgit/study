//1931
#include <bits/stdc++.h>

int n;
std::pair<int, int> arr[100001];//end start

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    for(int i = 0; i < n; i++) std::cin >> arr[i].second >> arr[i].first;
    std::sort(arr, arr + n);

    int ans = 0;
    int temp = 0;
    for(int i = 0; i < n; i++) {
        if(temp > arr[i].second) continue;
        ans++;
        temp = arr[i].first;
    }

    std::cout << ans;
}