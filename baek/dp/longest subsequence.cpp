//11053
#include <bits/stdc++.h>

int N;
int A[1000];

int table[1000];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        table[i] = 1;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(A[j] < A[i]) table[i] = std::max(table[i], table[j] + 1);
        }
    }

    std::cout << *std::max_element(table, table + N);
}