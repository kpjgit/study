//11052
#include <bits/stdc++.h>

int N;
int P[1001]; //P[i]는 카드 i개를 구매할 때의 최대 비용

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 1; i <= N; i++) std::cin >> P[i];

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j < i; j++) P[i] = std::max(P[i - j] + P[j], P[i]);
    }

    std::cout << P[N];
}