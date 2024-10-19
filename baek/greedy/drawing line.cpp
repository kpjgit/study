//2170
#include <bits/stdc++.h>

int N;
std::pair<int, int> arr[1000000];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) std::cin >> arr[i].first >> arr[i].second;
    std::sort(arr, arr + N);

    int ans = 0;
    int st = arr[0].first, en = arr[0].second;
    for(int i = 1; i < N; i++) {
        if(arr[i].first <= en) {
            en = std::max(en, arr[i].second);
        } else {
            ans += en - st;
            st = arr[i].first;
            en = arr[i].second;
        }

    }
    ans += en - st;
    
    std::cout << ans;
}