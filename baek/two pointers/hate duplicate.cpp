//20922
#include <bits/stdc++.h>

int N, K;
int arr[200000];

int used[100001];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> K;
    for(int i = 0; i < N; i++) std::cin >> arr[i];

    int st = 0;
    int en = 0;
    int ans = 0;
    while(st < N && en < N) {
        if(used[arr[en]] < K) {
            ans = std::max(ans, en - st + 1);
            used[arr[en]]++;
            en++;
        } else {
            used[arr[st]]--;
            st++;
        }
    }

    std::cout << ans;
}