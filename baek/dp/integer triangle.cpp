//1932
#include <bits/stdc++.h>

int n;
int temp[500];

int arr[500][500];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i + 1; j++) {
            std::cin >> temp[j];
        }

        if(i == 0) {
            arr[0][0] = temp[0];
            continue;
        }

        for(int j = 0; j < i + 1; j++) {
            if(j == 0) {
                arr[i][j] = arr[i - 1][j] + temp[j];
            } else if(j == i) {
                arr[i][j] = arr[i - 1][j - 1] + temp[j];
            } else {
                arr[i][j] = std::max(arr[i - 1][j - 1], arr[i - 1][j]);
                arr[i][j] += temp[j];
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(arr[n - 1][i] > ans) ans = arr[n - 1][i];
    }
    std::cout << ans;
}