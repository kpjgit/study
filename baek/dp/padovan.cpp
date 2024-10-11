//9461
#include <bits/stdc++.h>

int T;
int N;

long long P[100];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    P[0] = 1;
    P[1] = 1;
    P[2] = 1;
    P[3] = P[0] + P[1];
    P[4] = P[1] + P[2];
    P[5] = P[2] + P[3];

    for(int i = 3; i < 100; i++) P[i] = P[i - 3] + P[i - 2];

    std::cin >> T;
    for(int i = 0; i < T; i++) {
        std::cin >> N;
        std::cout << P[N - 1] << '\n';
    }
}