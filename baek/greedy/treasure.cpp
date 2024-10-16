//1026
#include <bits/stdc++.h>

int N;
int A[50];
int B[50];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) std::cin >> A[i];
    for(int i = 0; i < N; i++) std::cin >> B[i];
    std::sort(A, A + N);
    std::sort(B, B + N); //A를 재배열 하면 B도 재배열 하는것과 마찬가지

    int ans = 0;
    for(int i = 0; i < N; i++) ans += A[i] * B[N - i - 1];
    std::cout << ans;
}