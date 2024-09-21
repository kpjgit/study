//1182
#include <bits/stdc++.h>

int N, S;
int arr[20];

int ans = 0;

void func(int n, int s, int cnt, int sum) {
    if(sum == s) ans++;
    if(cnt == n) return;

    for(int i = cnt; i < n; i++) {

        int nxt = sum + arr[i];
        func(n, s, i + 1, nxt);
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> S;
    for(int i = 0; i < N; i++) std::cin >> arr[i];

    func(N, S, 0, 0);
    if(S == 0) ans--;
    std::cout << ans;
}