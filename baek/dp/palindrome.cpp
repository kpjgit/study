//10942
#include <bits/stdc++.h>

int N, M;
int arr[2000];
int S, E;

bool table[2000][2000]; //arr[i]~arr[j]까지의 팰린드롬 여부

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) std::cin >> arr[i];

    for(int i = 0; i < N; i++) {
        table[i][i] = true;
        
        if(i == 0) continue;
        if(arr[i - 1] == arr[i]) table[i - 1][i] = true;
    }

    for(int gap = 2; gap < N; gap++) {
        for(int i = 0; i < N - gap; i++) {
            int st = i;
            int en = i + gap;
            if(arr[st] == arr[en] && table[st + 1][en - 1] == true) table[st][en] = true;
            //안쪽의 더 작은 팰린드롬이 성립돼야 큰 팰린드롬이 가능
        }
    }

    std::cin >> M;
    for(int num = 0; num < M; num++) {
        std::cin >> S >> E;
        std::cout << table[S - 1][E - 1] << '\n';
    }
}