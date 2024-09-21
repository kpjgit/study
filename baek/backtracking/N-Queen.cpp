//9663
#include <bits/stdc++.h>

int N;

bool used_v[14];
bool used_d0[27];
bool used_d1[27];

int ans = 0;

void func(int n, int cnt) {
    if(cnt == n) {
        ans++;
        return;
    }

    for(int i = 0; i < n; i++) {
        if(used_v[i] || used_d0[cnt + i] || used_d1[cnt - i + n - 1]) continue;
    
    
        used_v[i] = true;
        used_d0[cnt + i] = true;
        used_d1[cnt - i + n - 1] = true;
        func(n, cnt + 1);
        used_v[i] = false;
        used_d0[cnt + i] = false;
        used_d1[cnt - i + n - 1] = false;
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    func(N, 0);
    std::cout << ans;
}