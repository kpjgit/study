//9372
#include <bits/stdc++.h>

int T, N, M; //신장 트리만을 구하므로 순서 등을 출력해야할 경우 priority_queue 대신 queue를 사용 가능

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> T;
    int temp;
    for(int num = 0; num < T; num++) {
        std::cin >> N >> M;
        for(int i = 0; i < M * 2; i++) std::cin >> temp;

        std::cout << N - 1 << '\n'; 
    }
}