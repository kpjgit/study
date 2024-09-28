//14891
#include <bits/stdc++.h>

char cogs[4][8]; //N: 0, S: 1
int K;
int cursor[4] = {}; //12시 방향

void rotate(int num, int dir, int init) {
    int prev = cursor[num];
    cursor[num] -= dir;
    if(cursor[num] < 0) cursor[num] = 8 + cursor[num];
    if(cursor[num] >= 8) cursor[num] = cursor[num] - 8;

    int left = num - 1, right = num + 1;
    
    if(left < init && left >= 0) {
        int adj = cursor[left] + 2;
        if(adj >= 8) adj = adj - 8;
        
        int cur = prev - 2;
        if(cur < 0) cur = 8 + cur;

        if(cogs[left][adj] != cogs[num][cur]) rotate(left, dir * -1, num);
    }

    if(right > init && right < 4) {
        int adj = cursor[right] - 2;
        if(adj < 0) adj = 8 + adj;

        int cur = prev + 2;
        if(cur >= 8) cur = cur - 8;

        if(cogs[right][adj] != cogs[num][cur]) rotate(right, dir * -1, num);
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 8; j++) std::cin >> cogs[i][j];
    }

    std::cin >> K;
    int num, dir;
    for(int i = 0; i < K; i++) {
        std::cin >> num >> dir;
        num--;

        rotate(num, dir, num);
    }

    int ans = 0;
    for(int i = 0; i < 4; i++) if(cogs[i][cursor[i]] == '1') ans += 1 << i;
    std::cout << ans;
}