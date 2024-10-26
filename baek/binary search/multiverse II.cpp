//18869
#include <bits/stdc++.h>

int M, N;

int arr[100][10000];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> M >> N;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) std::cin >> arr[i][j];

        std::vector<int> temp(arr[i], arr[i] + N);
        temp.erase(std::unique(temp.begin(), temp.end()), temp.end());
        for(int j = 0; j < N; j++) { //균일한 쌍일 경우에는 좌표 압축을 한 값이 서로 같다
            arr[i][j] = std::lower_bound(temp.begin(), temp.end(), arr[i][j]) - temp.begin();
        }
    }

    int cnt = 0;
    for(int i = 0; i < M - 1; i++) {
        for(int j = i + 1; j < M; j++) {
            bool add = true;
            for(int k = 0; k < N; k++) {
                if(arr[i][k] != arr[j][k]) {
                    add = false;
                    break;
                }
            }

            cnt += add;
        }
    }

    std::cout << cnt;
}