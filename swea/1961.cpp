#include <bits/stdc++.h>

int T;
int N;
int arr[7][7];

std::string ans[3][7];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> T;
    for(int num = 1; num <= T; num++) {
        std::cin >> N;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                std::cin >> arr[i][j];
            }

            ans[0][i].clear();
            ans[1][i].clear();
            ans[2][i].clear();
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                ans[0][i] += std::to_string(arr[N - j - 1][i]);
                ans[1][i] += std::to_string(arr[N - i - 1][N - j - 1]);
                ans[2][i] += std::to_string(arr[j][N - i - 1]);
            }
        }

        std::cout << '#' << num << '\n';
        for(int i = 0; i < N; i++) {
            std::cout << ans[0][i] << ' ' << ans[1][i] << ' ' << ans[2][i] << '\n';
        }
    }
}