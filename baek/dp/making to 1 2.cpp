//12852
#include <bits/stdc++.h>

int N;

int arr[1000001];
int route[1000001];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;

    arr[1] = 0;
    for(int i = 2; i <= N; i++) {
        arr[i] = arr[i - 1];
        route[i] = i - 1;

        if(i % 2 == 0) {
            if(arr[i] > arr[i / 2]) {
                arr[i] = arr[i / 2];
                route[i] = i / 2;
            }
        }

        if(i % 3 == 0) {
            if(arr[i] > arr[i / 3] ) {
                arr[i] = arr[i / 3];
                route[i] = i / 3;
            }
        }

        arr[i]++;
    }

    std::cout << arr[N] << '\n';
    int idx = N;
    std::cout << N << ' ';
    for(int i = 0; i < arr[N]; i++) {
        std::cout << route[idx] << ' ';
        idx = route[idx];
    }
}