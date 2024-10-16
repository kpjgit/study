//11047
#include <bits/stdc++.h>

int N, K;
int arr[10];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> K;
    for(int i = 0; i < N; i++) std::cin >> arr[i];

    int temp = 0;
    int ans = 0;
    for(int i = N - 1; i >= 0; i--) { //arr[i]는 arr[i-1]~arr[0]의 조합, arr[i]를 가능한 많이 써야 최소 횟수
        if(temp == K) break;
        ans += (K - temp) / arr[i];
        temp += (K - temp) / arr[i] * arr[i];
    }
    
    std::cout << ans;
}