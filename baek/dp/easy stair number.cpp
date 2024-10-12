//10844
#include <bits/stdc++.h>

int N;

long long arr[100][10]; //i-1 자릿수 일때 끝 자리수가 j인 숫자

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 1; i < 10; i++) arr[0][i] = 1;

    //arr[1][0] = 1; 10
    //arr[1][1] = 1; 21 01X
    //arr[1][2] = 2; 32 12
    //arr[1][3] = 2; 43 23
    //arr[1][4] = 2; 54 34
    //arr[1][5] = 2; 65 45
    //arr[1][6] = 2; 76 56
    //arr[1][7] = 2; 87 67
    //arr[1][8] = 2; 98 78
    //arr[1][9] = 1; 89
    //arr[i][j] = arr[i-1][j-1] + arr[i-1][j+1]
    //j의 앞에 arr[i-1][j-1], arr[i-1][j+1]을 붙인것과 같음

    for(int i = 1; i < N; i++) {
        for(int j = 0; j < 10; j++) {
            if(j != 0) arr[i][j] += arr[i - 1][j - 1];
            if(j != 9) arr[i][j] += arr[i - 1][j + 1];
            arr[i][j] %= 1000000000;
        }
    }

    long long ans = 0;
    for(int i = 0; i < 10; i++) ans = (ans + arr[N - 1][i]) % 1000000000;
    std::cout << ans;
}