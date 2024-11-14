#include <bits/stdc++.h>

int N;
int building[1000];

int dx[4] = {-2, -1, 1, 2};

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for(int num = 1; num <= 10; num++) {
        std::cin >> N;
        for(int i = 0; i < N; i++) {
            std::cin >> building[i];
        }

        int ans = 0;
        for(int i = 2; i < N - 2; i++) {
            int mx = 0;

            for(int dir = 0; dir < 4; dir++) {
                mx = std::max(mx, building[i + dx[dir]]);
            }

            if(building[i] > mx) ans += building[i] - mx;
        }
        std::cout << '#' << num << ' ' << ans << '\n';
    }
}