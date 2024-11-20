//2240
#include <bits/stdc++.h>

int T, W;
int arr[1001];

int table[1001][31]; //table[i][j]일때 i초가 지났을 때 j번 움직였을 때 얻을 수 있는 최대 갯수

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> T >> W;
    for(int i = 1; i <= T; i++) std::cin >> arr[i];

    if(arr[1] == 1) {
        table[1][0] = 1;
        table[1][1] = 0;
    } else {
        table[1][0] = 0;
        table[1][1] = 1;
    }

    for(int i = 2; i <= T; i++) {
        for(int j = 0; j <= W; j++) {
            if(j > i) break;
            
            if(j == 0) table[i][j] = table[i - 1][j];
            else table[i][j] = std::max(table[i - 1][j - 1], table[i - 1][j]);

            if(j % 2 == 0) { //j번 움직였을 때 1번 사과 나무 밑
                if(arr[i] == 1) table[i][j]++;
            } else {
                if(arr[i] == 2) table[i][j]++;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i <= W; i++) ans = std::max(ans, table[T][i]);
    std::cout << ans;
}