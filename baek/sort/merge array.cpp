//11728
#include <bits/stdc++.h>

int N, M;

int a[1000000];
int b[1000000];

//int result[2000000];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;
    for(int i = 0; i < N; i++) std::cin >> a[i];
    for(int i = 0; i < M; i++) std::cin >> b[i];

    int idx_a = 0;
    int idx_b = 0;
    int temp;
    for(int i = 0; i < N + M; i++) {
        if(idx_a == N) temp = b[idx_b++];
        else if(idx_b == M) temp = a[idx_a++];
        else {
            if(a[idx_a] > b[idx_b]) temp = b[idx_b++];
            else temp = a[idx_a++];
        }

        std::cout << temp << ' ';
    }
}