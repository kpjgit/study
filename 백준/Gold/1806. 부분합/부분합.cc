#include <bits/stdc++.h>

int N, S;
int arr[100000];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> S;
    for(int i = 0; i < N; i++) std::cin >> arr[i];
    
    int sum = arr[0];
    int ans = 100000;
    int st = 0;
    int en = 0;
    while(st < N && en < N) {
        if(sum < S) {
            en++;
            sum += arr[en];
        } else {
            ans = std::min(ans, en - st + 1);
            sum -= arr[st];
            st++;
        }
    }

    if(ans == 100000) ans = 0;
    std::cout << ans;
}