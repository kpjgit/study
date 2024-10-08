//15688
#include <bits/stdc++.h>

int N;

int table[20000003];

const int mid = 10000000;
int min = 20000002;
int max = 0;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    int temp;
    for(int i = 0; i < N; i++) {
        std::cin >> temp;
        temp += mid;
        table[temp]++;

        min = std::min(min, temp);
        max = std::max(max, temp);
    }

    for(int i = min; i <= max; i++) {
        for(int j = 0; j < table[i]; j++) std::cout << i - mid << '\n';
    }
}