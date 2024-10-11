//2193
#include <bits/stdc++.h>

int N;

long long arr[90];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    arr[0] = 1; //1
    arr[1] = 1; //10
    arr[2] = 2; //100 101 -> (10 0), (1 01)
    arr[3] = 3; //1000 1001 1010 -> (100 0, 101 0), (10 01)
    arr[4] = 5; //10000 10001 10010 10100 10101 -> (1000 0, 1001 0, 1010 0), (100 01, 101 01)
    arr[5] = 8; //100000 100001 100010 100100 101000 100101 101001 101010
    for(int i = 2; i < N; i++) arr[i] = arr[i - 1] + arr[i - 2]; //뒷자리가 0일경우 arr[n - 1], 뒷자리가 1일경우 무조건 01이 나와야 하므로 arr[n - 2]

    std::cout << arr[N - 1];
}