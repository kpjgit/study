//2230
#include <bits/stdc++.h>

int N, M;
int A[100000];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;
    for(int i = 0; i < N; i++) std::cin >> A[i];
    std::sort(A, A + N);

    int st = 0;
    int en = 0;
    int ans = 2000000000;
    while(st < N && en < N) {
        if(A[en] - A[st] < M) en++;
        else {
            ans = std::min(ans, A[en] - A[st]);
            st++;
        }
    }

    std::cout << ans;
}