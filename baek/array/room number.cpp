//1475
#include <bits/stdc++.h>

int n, x;
int arr[100000];
bool did[2000001];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int ans = 0;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    std::cin >> x;

    for(int i = 0; i < n; i++) {
        if(arr[i] >= x) continue;

        if(did[x - arr[i]]) ans++;
        did[arr[i]] = true;
    }

    std::cout << ans;
}