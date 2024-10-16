//12865 그리디 아님 dp로 풀이
#include <bits/stdc++.h>

int N, K;
std::pair<int, int> arr[101]; //W, V
int table[100001][101]; //배낭 무게가 i, 물건 j를 넣지 말지 결정

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> N >> K;
    for(int i = 1; i <= N; i++) std::cin >> arr[i].first >> arr[i].second;

    for(int i = 1; i <= K; i++) {
        for(int j = 1; j <= N; j++) {
            if(i >= arr[j].first) table[i][j] = std::max(table[i][j - 1], table[i - arr[j].first][j - 1] + arr[j].second);
            else table[i][j] = table[i][j - 1];
        }
    }

    std::cout << table[K][N];
}