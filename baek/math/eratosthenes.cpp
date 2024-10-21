//2960
#include <bits/stdc++.h>

int N, K;

std::vector<bool> v(1001, true);

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int cnt = 0;
    std::cin >> N >> K;
    v[0] = v[1] = false;
    for(int i = 2; i <= N; i++) {
        if(v[i] == false) continue;

        cnt++;
        for(int j = i + i; j <= N; j += i) {
            if(v[j] == false) continue;

            v[j] = false;
            cnt++;
            if(cnt == K) {
                std::cout << j;
                return 0;
            }
        }

        if(cnt == K) {
            std::cout << i;
            break;
        }
    }
}