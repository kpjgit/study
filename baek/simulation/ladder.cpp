//15684
#include <bits/stdc++.h>

int N, M, H;

bool used[30][11]; //인덱싱을 위해 양 옆으로 1씩 여유공간을 둠

int ans = 300;

bool check() {
    for(int i = 1; i <= N; i++) {
        int cur = i;
        for(int j = 0; j < H; j++) {
            if(used[j][cur - 1] == true) cur--;
            else if(used[j][cur] == true) cur++;
        }

        if(cur != i) return false;
    }

    return true;
}

void func(int cnt, int row = 0, int col = 1) {
    if(cnt == 3) return;

    for(int i = row; i < H; i++) {
        int nextj = (i == row) ? col : 1;
        for(int j = nextj; j <= N - 1; j++) {
            if(used[i][j] == true || used[i][j - 1] == true || used[i][j + 1] == true) continue;

            used[i][j] = true;

            if(check()) {
                ans = std::min(ans, cnt + 1);
                used[i][j] = false;
                return; //더 탐색할 의미가 없음
            }
            else func(cnt + 1, i, j + 1);
            
            used[i][j] = false;
        }
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M >> H;

    int v, h;
    for(int i = 0; i < M; i++) {
        std::cin >> v >> h;

        used[v - 1][h] = true;
    }

    if(check()) ans = 0;
    else func(0);

    if(ans == 300) std::cout << -1;
    else std::cout << ans;
}