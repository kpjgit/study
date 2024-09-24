//6603
#include <bits/stdc++.h>

int k;
int arr[49];
int ans[49];
bool used[49];

void func(int n, int cnt) {
    if(cnt == 6) {
        for(int i = 0; i < 6; i++) std::cout << ans[i] << ' ';
        std::cout << '\n';
        return;
    }

    for(int i = 0; i < n; i++) {
        if(used[i] == true) continue;
        if(cnt != 0 && arr[i] < ans[cnt - 1]) continue;
        used[i] = true;
        ans[cnt] = arr[i];
        func(n, cnt + 1);
        used[i] = false;
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    while(true) {
        std::cin >> k;
        if(k == 0) break;
        for(int i = 0; i < k; i++) std::cin >> arr[i];
        func(k, 0);
        std::cout << '\n';
    }
}