//12100
#include <bits/stdc++.h>

int N;
int input[20][20];
int board[20][20];

void func(int dir) {
    int idx;
    if(dir == 0) { //오른쪽으로 기울이기
        for(int i = 0; i < N; i++) {
            idx = N - 1;
            int temp[20] = {};
            for(int j = N - 1; j >= 0; j--) {
                if(board[i][j] == 0) continue; //옮길게 없음

                if(temp[idx] == 0) { //자리가 비어있음
                    temp[idx] = board[i][j];
                } else if(temp[idx] == board[i][j]) { //합치기
                    temp[idx] *= 2;
                    idx--;
                } else {
                    idx--;
                    temp[idx] = board[i][j];
                }
            }

            for(int j = N - 1; j >= 0; j--) board[i][j] = temp[j];
        }
    } else if(dir == 1) { //아래로 기울이기
        for(int j = 0; j < N; j++) {
            idx = N - 1;
            int temp[20] = {};
            for(int i = N - 1; i >= 0; i--) {
                if(board[i][j] == 0) continue;

                if(temp[idx] == 0) {
                    temp[idx] = board[i][j];
                } else if(temp[idx] == board[i][j]) {
                    temp[idx] *= 2;
                    idx--;
                } else {
                    idx--;
                    temp[idx] = board[i][j];
                }
            }

            for(int i = N - 1; i >= 0; i--) board[i][j] = temp[i];
        }
    } else if(dir == 2) {
        for(int i = 0; i < N; i++) {
            idx = 0;
            int temp[20] = {};
            for(int j = 0; j < N; j++) {
                if(board[i][j] == 0) continue;

                if(temp[idx] == 0) {
                    temp[idx] = board[i][j];
                } else if(temp[idx] == board[i][j]) {
                    temp[idx] *= 2;
                    idx++;
                } else {
                    idx++;
                    temp[idx] = board[i][j];
                }
            }

            for(int j = 0; j < N; j++) board[i][j] = temp[j];
        }
    } else if(dir == 3) {
        for(int j = 0; j < N; j++) {
            idx = 0;
            int temp[20] = {};
            for(int i = 0; i < N; i++) {
                if(board[i][j] == 0) continue;

                if(temp[idx] == 0) {
                    temp[idx] = board[i][j];
                } else if(temp[idx] == board[i][j]) {
                    temp[idx] *= 2;
                    idx++;
                } else {
                    idx++;
                    temp[idx] = board[i][j];
                }
            }
            
            for(int i = 0; i < N; i++) board[i][j] = temp[i];
        }
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) std::cin >> input[i][j];
    }

    int ans = 0;
    for(int num = 0; num < (1 << (2 * 5)); num++) {
        for(int i = 0; i < N; i++) { //초기화
            for(int j = 0; j < N; j++) board[i][j] = input[i][j];
        }

        int brute = num;
        for(int i = 0; i < 5; i++) {
            int dir = brute % 4;
            brute /= 4;
            func(dir);
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(board[i][j] > ans) ans = board[i][j];
            }
        }
    }
    
    std::cout << ans;
}