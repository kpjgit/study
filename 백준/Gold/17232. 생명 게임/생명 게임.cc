#include <bits/stdc++.h>

int N, M, T;
int K, a, b;

char map[101][101];
int acc[101][101]; //0번 인덱스는 0

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> N >> M >> T;
    std::cin >> K >> a >> b;
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            std::cin >> map[i][j];
        }
    }
    
    while(T > 0) { // T * N * M
        for(int i = 1; i <= N; i++) { //누적합 갱신
            for(int j = 1; j <= M; j++) {
                if(map[i][j] == '*') acc[i][j] = 1;
                else acc[i][j] = 0;
                
                acc[i][j] += acc[i - 1][j] + acc[i][j - 1] - acc[i - 1][j - 1];
            }
        }
        
        for(int i = 1; i <= N; i++) { //맵 갱신
            for(int j = 1; j <= M; j++) {
                int right = std::min(j + K, M);
                int bottom = std::min(i + K, N);
                
                int left = std::max(j - K, 1);
                int top = std::max(i - K, 1);
                
                int sum = acc[bottom][right] + acc[top - 1][left - 1] - acc[top - 1][right] - acc[bottom][left - 1];
                
                if(map[i][j] == '*') { //생명이 있는 칸
                    sum--;
                    if(sum < a || sum > b) map[i][j] = '.';
                    
                } else {
                    if(sum > a && sum <= b) map[i][j] = '*';
                }
            }
        }
        
        T--;
    }
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            std::cout << map[i][j];
        }
        std::cout << '\n';
    }
}