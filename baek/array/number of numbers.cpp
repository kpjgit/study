//2577
#include <bits/stdc++.h>

int A, B ,C;
int arr[10];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> A >> B >> C;
    int result = A * B * C;

    while(result > 0) {
        arr[result % 10]++;
        result /= 10;
    }

    for(int i = 0; i < 10; i++) std::cout << arr[i] << '\n';
}