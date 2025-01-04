#include <bits/stdc++.h>

int T;
int N, M;
int A[20];
int B[20];

int func() {
    int ans = 0;

    if(N < M) {
        std::swap(A, B);
        std::swap(N, M);
    }
    int gap = N - M;

    for(int i = 0; i <= gap; i++) {
        int temp = 0;
        for(int j = 0; j < M; j++) { //M은 항상 N보다 작다
            temp += A[j + i] * B[j];
        }

        ans = std::max(temp, ans);
    }

    return ans;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> T;
    for(int num = 1; num <= T; num++) {
        std::cin >> N >> M;
        for(int i = 0; i < N; i++) std::cin >> A[i];
        for(int i = 0; i < M; i++) std::cin >> B[i];

        std::cout << '#' << num << ' ' << func() << '\n';
    }
}