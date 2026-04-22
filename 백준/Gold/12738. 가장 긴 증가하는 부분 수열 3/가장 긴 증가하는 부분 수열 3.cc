#include <bits/stdc++.h>

int N;
int arr[1'000'000];

int cnt = 0;
int table[1'000'000];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) std::cin >> arr[i];

    table[cnt] = arr[0];
    cnt++;

    for(int i = 1; i < N; i++) {
        if(table[cnt - 1] < arr[i]) {
            table[cnt] = arr[i];
            cnt++;
        } else {
            int* loc = std::lower_bound(table, table + cnt, arr[i]);
            *loc = arr[i];
        }
    }

    std::cout << cnt;
}