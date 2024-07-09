//18808
#include <bits/stdc++.h>

int n, m, k;
bool notebook[50][50];
int r, c;
bool sticker[10][10];

bool can_stick(int x, int y) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(notebook[x + i][y + j] == 1 && sticker[i][j] == 1) return false; 
        }
    }
    for(int i = 0; i < r; i++) {
        for(int j = 0; j <c; j++) {
            if(sticker[i][j] == 1) notebook[x + i][y + j] = 1; 
        }
    }

    return true;
}

void rotate() {
    bool temp[10][10];
    for(int i = 0; i < r; i++) {
        for(int j = 0; j <c; j++) {
            temp[i][j] = sticker[i][j];
        }
    }

    for(int i = 0; i < c; i++) {
        for(int j = 0; j < r; j++) {
            sticker[i][j] = temp[r - 1 - j][i];
        }
    }

    std::swap(r, c);
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m >> k;

    while(k--) {
        std::cin >> r >> c;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                std::cin >> sticker[i][j];
            }
        }

        for(int rot = 0; rot < 4; rot++) {
            bool did = false;
            for(int i = 0; i <= n - r; i++) {
                if(did) break;
                for(int j = 0; j <= m - c; j++) {
                    if(can_stick(i, j)) {
                        did = true;
                        break;
                    }
                }
            }
            if(did) break;
            rotate();
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            ans += notebook[i][j];
        }
    }
    std::cout << ans << '\n';
}