//18808
#include <bits/stdc++.h>

int N, M, K;
int R, C;
bool laptop[40][40];
bool sticker[10][10];

bool stick(int x, int y) {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(laptop[x + i][y + j] == true && sticker[i][j] == true) return false;
        }
    }
    
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) if(sticker[i][j] == true) laptop[x + i][y + j] = true;
    }
    return true;
}

void rotate() {
    int temp[10][10];
    for(int i = 0; i < C; i++) {
        for(int j = 0; j < R; j++) temp[i][j] = sticker[R - j - 1][i];
    }
    
    std::swap(R, C);
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) sticker[i][j] = temp[i][j];
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M >> K;
    for(int num = 0; num < K; num++) {
        std::cin >> R >> C;
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) std::cin >> sticker[i][j];
        }

        for(int rot = 0; rot < 4; rot++) {
            bool escape = false;
            for(int i = 0; i <= N - R; i++) {
                for(int j = 0; j <= M - C; j++) {
                    escape = stick(i, j);
                    if(escape == true) break;
                }
                if(escape == true) break;
            }
            if(escape == true) break;
            rotate();
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) if(laptop[i][j] == true) ans++;
    }

    std::cout << ans;
}