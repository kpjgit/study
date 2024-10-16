//1931
#include <bits/stdc++.h>

int N;
std::pair<int, int> arr[100000];//시작, 끝

bool cmp(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    if(a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) {
        int st, en;
        std::cin >> st >> en;
        arr[i] = {st, en};
    }
    std::sort(arr, arr + N, cmp);

    int ans = 0;
    int temp = -1;
    for(int i = 0; i < N; i++) {
        if(arr[i].first >= temp) {
            temp = arr[i].second;
            ans++;
        }
    }

    std::cout << ans;
}