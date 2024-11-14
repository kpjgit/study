#include <bits/stdc++.h>

int T;
int N, P;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> T;
    for(int num = 0; num < T; num++) {
        std::cin >> N >> P;

        int cur = 0;
        for(int i = 1; i <= N; i++) {
            cur += i;
            if(cur == P) cur--; //만약 순차적으로 올라가다 현재 층이 P와 같은 경우가 발생한다면
                                //첫번째 층을 건너뛰었을 때 P-1층에 도달한다는 것과 같다
        }

        std::cout << cur << '\n';
    }
}