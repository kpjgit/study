//2630
#include <bits/stdc++.h>

int N;
int paper[128][128];

void func(int n, int x, int y, int& a, int& b) {
    const int chk = paper[x][y];

    if(n == 1) {
        if(chk == 0) a++;
        if(chk == 1) b++;
        return;
    }
    
    bool escape = false;
    for(int i = x; i < x + n; i++) {
        for(int j = y; j < y + n; j++) {
            if(chk != paper[i][j]) {
                escape = true;
                break;
            }
        }
        if(escape) break;
    }

    int next = n / 2;
    if(escape) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                func(next, x + i * next, y + j * next, a, b);
            }
        }
    } else {
        if(chk == 0) a++;
        if(chk == 1) b++;
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) std::cin >> paper[i][j];
    }

    int ans0 = 0, ans1 = 0;
    func(N, 0, 0, ans0, ans1);
    std::cout << ans0 << '\n' << ans1;
}