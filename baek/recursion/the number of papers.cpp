//1780
#include <bits/stdc++.h>

int N;
int paper[2200][2200];

void func(int n, int x, int y, int& a, int& b, int& c) {
    const int chk = paper[x][y];

    if(n == 1) {
        if(chk == -1) a++;
        if(chk == 0) b++;
        if(chk == 1) c++;
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

    int next = n / 3;
    if(escape) {
        func(next, x, y, a, b, c);
        func(next, x, y + next, a, b, c);
        func(next, x, y + next * 2, a, b, c);
        func(next, x + next, y, a, b, c);
        func(next, x + next, y + next, a, b, c);
        func(next, x + next, y + next * 2, a, b, c);
        func(next, x + next * 2, y, a, b, c);
        func(next, x + next * 2, y + next, a, b, c);
        func(next, x + next * 2, y + next * 2, a, b, c);
    } else {
        if(chk == -1) a++;
        if(chk == 0) b++;
        if(chk == 1) c++;
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) std::cin >> paper[i][j];
    }

    int ans0 = 0, ans1 = 0, ans2 = 0;
    func(N, 0, 0, ans0, ans1, ans2);
    std::cout << ans0 << '\n' << ans1 << '\n' << ans2 << '\n';
}