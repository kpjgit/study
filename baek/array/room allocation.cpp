//13300
#include <bits/stdc++.h>

int N, K;
int arr[2][6];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int ans = 0;
    std::cin >> N >> K;
    for(int i = 0; i < N; i++) {
        int gender, grade;
        std::cin >> gender >> grade;
        arr[gender][grade - 1]++;
    }

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 6; j++) {
            if(arr[i][j] % K == 0) ans += arr[i][j] / K;
            else ans += arr[i][j] / K + 1;
        }
    }

    std::cout << ans;
}