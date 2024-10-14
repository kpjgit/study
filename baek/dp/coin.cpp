//9084
#include <bits/stdc++.h>

int T, N, M;
int coin[20];

int arr[10001]; //arr[i]는 i를 만드는 조합의 갯수

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> T;
    for(int num = 0; num < T; num++) {
        std::fill(arr, arr + 10000, 0);
        std::cin >> N;
        for(int i = 0; i < N; i++) std::cin >> coin[i];
        std::cin >> M;

        arr[0] = 1; //값을 0으로 만드는 방법은 한가지만 있다
        for(int i = 0; i < N; i++) {
            for(int j = coin[i]; j <= M; j++) {
                arr[j] += arr[j - coin[i]]; //j를 만드는 방법의 갯수는 j - coin을 만드는 갯수의 합
            }
        }

        std::cout << arr[M] << '\n';
    }
}