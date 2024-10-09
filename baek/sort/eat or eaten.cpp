//7795
#include <bits/stdc++.h>

int T;
int N, M;

int A[20000];
int B[20000];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> T;
    for(int num = 0; num < T; num++) {
        int ans = 0;
        std::cin >> N >> M;
        for(int i = 0; i < N; i++) std::cin >> A[i];
        for(int i = 0; i < M; i++) std::cin >> B[i];

        std::sort(A, A + N);
        std::sort(B, B + M);

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(A[i] > B[j]) ans++;
                else break;
            }
        }

        std::cout << ans << '\n';
    }
}