//1992
#include <bits/stdc++.h>

int N;
char arr[64][64];

void func(int n, int x, int y, std::string& str) {
    const char chk = arr[x][y];
    if(n == 1) {
        str.append(1, chk);
        return;
    }

    bool escape = false;
    for(int i = x; i < x + n; i++) {
        for(int j = y; j < y + n; j++) {
            if(chk != arr[i][j]) {
                escape = true;
                break;
            }
        }
        if(escape) break;
    }

    int next = n / 2;
    if(escape) {
        str.append(1, '(');
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                func(next, x + i * next, y + j * next, str);
            }
        }
        str.append(1, ')');
    } else {
        str.append(1, chk);
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) std::cin >> arr[i][j];
    }

    std::string ans;
    func(N, 0, 0, ans);
    std::cout << ans;
}