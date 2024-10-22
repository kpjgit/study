//1011
#include <bits/stdc++.h>

int T, x, y;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> T;
    for(int num = 0; num < T; num++) {
        std::cin >> x >> y;

        int dist = y - x; //1: 1 1, 2: 11 2, 3: 111 3, 4: 121 4, 5: 1211 4, 6: 1221 4, 7: 12211 5, 8: 12221 5, 9: 12321 5, 10: 123211 6
        int sq = std::sqrt(dist); //제곱수 dist의 sqrt(dist)가 최대 이동거리

        int ans;
        if(sq * sq == dist) ans = 2 * sq - 1;
        else if(sq * sq + sq >= dist) ans = 2 * sq; //제곱수와 다음 제곱수 사이에서 dist - sq * sq >= sq이면 제곱수에서 sq이하만큼 한번만 더 움직이면 됨
        else ans = 2 * sq + 1;

        std::cout << ans << '\n';
    }
}