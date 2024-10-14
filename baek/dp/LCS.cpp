//9251
#include <bits/stdc++.h>

std::string s0;
std::string s1;

int arr[1001][1001]; //arr[i][j]는 s0의 0~i-1까지와 s1의 0~j-1까지의 최대 공통 수열의 길이

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> s0 >> s1;
    for(int i = 1; i <= s0.size(); i++) {
        for(int j = 1; j <= s1.size(); j++) {
            if(s0[i - 1] == s1[j - 1]) arr[i][j] = arr[i - 1][j - 1] + 1; //i, j에서 같다면 i-1, j-1까지의 수열에 붙일 수 있다
            else arr[i][j] = std::max(arr[i - 1][j], arr[i][j - 1]); //연속하지 않아도 되므로 인접한 곳에서 가장 큰 수를 가져온다
        }
    }

    std::cout << arr[s0.size()][s1.size()];
}