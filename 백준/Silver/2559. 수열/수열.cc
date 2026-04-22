#include <iostream>

int N, K;
int arr[100001];

int sum[100001];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> N >> K;
    for(int i = 1; i <= N; i++) {
        std::cin >> arr[i];
        sum[i] = arr[i] + sum[i - 1];
    }
    
    int ans = -10000001;
    for(int i = K; i <= N; i++) {
        int temp = sum[i] - sum[i - K];
        if(ans < temp) ans = temp;
    }
    
    std::cout << ans;
}