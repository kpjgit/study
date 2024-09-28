//14499
#include <bits/stdc++.h>

int N, M, x, y, K;
int board[20][20];
int dice[3][3] = {};
int dice_top = 0;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void roll(int dir) {
    int temp;
    std::swap(dice_top, dice[1 - dx[dir]][1 - dy[dir]]);

    if(dir == 0) {
        temp = dice[1][0];
        for(int i = 0; i < 2; i++) {
            dice[1][i] = dice[1][i + 1];
        }
        dice[1][2] = temp;
    } else if(dir == 1) {
        temp = dice[1][2];
        for(int i = 2; i > 0; i--) {
            dice[1][i] = dice[1][i - 1];
        }
        dice[1][0] = temp;
    } else if(dir == 2) {
        temp = dice[2][1];
        for(int i = 2; i > 0; i--) {
            dice[i][1] = dice[i - 1][1];
        }
        dice[0][1] = temp;
    } else {
        temp = dice[0][1];
        for(int i = 0; i < 2; i++) {
            dice[i][1] = dice[i + 1][1];
        }
        dice[2][1] = temp;
    }

    std::cout << dice_top << '\n';
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M >> x >> y >> K;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) std::cin >> board[i][j];
    }

    int input;
    int nx, ny;
    for(int i = 0; i < K; i++) {
        std::cin >> input;
        input--;
        nx = x + dx[input];
        ny = y + dy[input];

        if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        
        roll(input);
        x = nx;
        y = ny;
        if(board[x][y] == 0) board[x][y] = dice[1][1];
        else {
            dice[1][1] = board[x][y];
            board[x][y] = 0;
        }
    }
}