//12852
#include <bits/stdc++.h>

int x;
int arr[1000005];
int route[1000005];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> x;

    arr[1] = 0;
    for(int i = 2; i <= x; i++) {
        arr[i] = arr[i - 1] + 1;
        route[i] = i - 1;
        if(i % 2 == 0 && arr[i] > arr[i / 2] + 1) {
            arr[i] = arr[i / 2] + 1;
            route[i] = i / 2;
        }
        if(i % 3 == 0 && arr[i] > arr[i / 3] + 1) {
            arr[i] = arr[i / 3] + 1;
            route[i] = i / 3;
        }
    }

    std::cout << arr[x] << '\n';
    int cur = x;
    while(1) {
        std::cout << cur << ' ';
        if(cur == 1) break;
        cur = route[cur];
    }
}