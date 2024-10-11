//14501
#include <bits/stdc++.h>

int N;
int T[15], P[15];

int table[16]; //i번째 날에 상담을 시작할 경우의 최대 수익, i-1은 미리 계산된 i를 활용할 수 있다

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) std::cin >> T[i] >> P[i];

    for(int i = N - 1; i >= 0; i--) {
        if(i + T[i] <= N) {
            table[i] = std::max(table[i + T[i]] + P[i], table[i + 1]);
        } else table[i] = table[i + 1];
    }

    std::cout << *std::max_element(table, table + N);
}