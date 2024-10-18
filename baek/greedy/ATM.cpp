//11399
#include <bits/stdc++.h>

int N;
int arr[1000];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) std::cin >> arr[i];
    std::sort(arr, arr + N); //누적 합이 가장 작아야 되니 가장 적은 대기시간이 앞으로 와야한다

    int ans = 0;
    int sum = 0;
    for(int i = 0; i < N; i++) {
        ans += sum + arr[i];
        sum += arr[i];
    }

    std::cout << ans;
}