//1915
#include <bits/stdc++.h>

int n, m;
int arr[1001][1001];

int table[1001][1001]; //table[i][j]는 i, j를 끝으로 하는 가장 큰 정사각형

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    std::string s;
    for(int i = 1; i <= n; i++) {
        std::cin >> s;
        for(int j = 1; j <= m; j++) arr[i][j] = s[j - 1] - '0';
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(arr[i][j] == false) continue;

            table[i][j] = std::min({table[i - 1][j], table[i][j - 1], table[i - 1][j - 1]}) + 1;
            //각각 i, j로부터 바로 왼쪽, 위, 대각선의 정사각형, 값에 따라 i, j로 오도록 정사각형을 잡아 늘릴 수 있다
            //각 방향에서 가장 작은 값이 i, j의 크기를 결장한다
            ans = std::max(ans, table[i][j]);
        }
    }

    std::cout << ans * ans;
}