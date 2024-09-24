//16987
#include <bits/stdc++.h>

int N;
int eggs[2][8]; //내구, 무게

int ans = 0;

void func(int n, int cnt, int temp) {
    if(cnt == n) {
        ans = std::max(ans, temp);
        return;
    }

    if(eggs[0][cnt] <= 0 || temp == n - 1) {
        
        func(n, cnt + 1, temp);
        return;
    }

    for(int i = 0; i < n; i++) {
        if(cnt == i || eggs[0][i] <= 0) continue;
        
        eggs[0][cnt] -= eggs[1][i];
        eggs[0][i] -= eggs[1][cnt];
        if(eggs[0][cnt] <= 0) temp++;
        if(eggs[0][i] <= 0) temp++;

        func(n, cnt + 1, temp);

        if(eggs[0][cnt] <= 0) temp--;
        if(eggs[0][i] <= 0) temp--;
        eggs[0][cnt] += eggs[1][i];
        eggs[0][i] += eggs[1][cnt];
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) {
        std::cin >> eggs[0][i] >> eggs[1][i];
    }

    func(N, 0, 0);
    std::cout << ans;
}