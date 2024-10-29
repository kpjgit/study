//2003
#include <bits/stdc++.h>

int N, M;
int arr[10000];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;
    for(int i = 0; i < N; i++) std::cin >> arr[i];

    int st = 0;
    int en = 0;
    int ans = 0;
    int sum = arr[0];
    while(st < N && en < N) {
        if(sum < M) {
            en++;
            sum += arr[en];
        } else {
            if(sum == M) ans++;
            sum -= arr[st];
            st++;
        }
    }

    std::cout << ans;
}