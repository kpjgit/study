//11055
#include <bits/stdc++.h>

int N;
int A[1000];

int table[1000]; //A[i]의 원소를 마지막으로 갖는 값중 가장 큰 값

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        table[i] = A[i];
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(A[j] < A[i]) table[i] = std::max(table[i], table[j] + A[i]);
        }
    }

    std::cout << *std::max_element(table, table + N);
}