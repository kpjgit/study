#include <iostream>
#include <algorithm>

int N, M;
char board[50][50];

char color[] = {'W', 'B'};

int func(int x, int y, int col) {
    int ret = 0;
    for(int i = x; i < x + 8; i++) {
        col = (col + 1) % 2;
        for(int j = y; j < y + 8; j++) {
            if(board[i][j] != color[col]) ret++;
            col = (col + 1) % 2;
        }
    }
    
    return ret;
}

int main(void) {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    
    std::cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> board[i][j];
        }
    }
    
    int ans = 2500;
    for(int i = 0; i < N - 7; i++) {
        for(int j = 0; j < M - 7; j++) {
            for(int k = 0; k < 2; k++) {
                ans = std::min(ans, func(i, j, k));
            }
        }
    }
    
    std::cout << ans;
}