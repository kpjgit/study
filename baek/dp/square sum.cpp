//1699
#include <bits/stdc++.h>

int N;

int arr[100001]; //arr[i]는 i의 제곱수 합의 최소, arr[i-j^2] + 1(j^j로 i에서 뺀값)는 arr[i]의 후보가 될 수 있다

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    arr[1] = 1;
    for(int i = 2; i <= N; i++) {
        arr[i] = i + 1; //1*i, 제곱수 합의 최대
        for(int j = 1; j * j <= i; j++) {
            arr[i] = std::min(arr[i], arr[i - j * j] + 1);
        }
    }

    std::cout << arr[N];
}