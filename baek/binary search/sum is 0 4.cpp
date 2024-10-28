//7453
#include <bits/stdc++.h>

int N;
int A[4000];
int B[4000];
int C[4000];
int D[4000];

int AB[16000000];
int CD[16000000];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) std::cin >> A[i] >> B[i] >> C[i] >> D[i];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            AB[i * N + j] = A[i] + B[j];
            CD[i * N + j] = C[i] + D[j];
        }
    }
    std::sort(AB, AB + N * N);
    std::sort(CD, CD + N * N);

    long long cnt = 0;
    int num = 1;
    for(int i = 0; i < N * N; i++) {
        if(i < N * N - 1 && AB[i] == AB[i + 1]) {
            num++;
        } else {
            cnt += num * (std::upper_bound(CD, CD + N * N, -AB[i]) - std::lower_bound(CD, CD + N * N, -AB[i]));
            num = 1;
        }
    }

    std::cout << cnt;
}