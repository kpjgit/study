#include <iostream>
#include <algorithm>

const int INF = 1e9;

int N;
int board[16][16];

int table[16][1 << 16];

int dfs(int cur, int mask) {
    if(mask == (1 << N) - 1) {
        if(board[cur][0] == 0) return INF;
        return board[cur][0];
    }
    
    int& ret = table[cur][mask];
    if(ret != -1) return ret;
    
    ret = INF;
    
    for(int nxt = 0; nxt < N; nxt++) {
        if(mask & (1 << nxt)) continue;
        if(board[cur][nxt] == 0) continue;
        
        ret = std::min(ret, board[cur][nxt] + dfs(nxt, mask | (1 << nxt)));
    }
    
    return ret;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> board[i][j];
        }
    }
    
    for(int i = 0; i < N; i++) {
        std::fill(table[i], table[i] + (1 << N), -1);
    }
    
    std::cout << dfs(0, 1);
}