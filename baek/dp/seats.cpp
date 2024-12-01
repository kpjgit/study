//2302
#include <bits/stdc++.h>

int N, M;
std::queue<int> vip;

int table[41];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;
    int temp;
    vip.push(0);
    for(int i = 0; i < M; i++) {
        std::cin >> temp;
        vip.push(temp);
    }
    vip.push(N + 1);

    table[2] = 2;
    table[3] = 3;
    for(int i = 4; i <= N; i++) table[i] = table[i - 1] + table[i - 2];
                            //12 21   123 213 132   1234 2134 2143 1324 1243   12345 21345 21435 21354 13245 13254 12435 12354
                            //i명을 연속으로 앉히는건 i-1을 앉힌 후 그 끝에 i를 앉히는 것과 i-2를 앉힌 후 그 끝에 i와 i-1 순서로 앉힌 것의 합과 같다
    int st = vip.front();
    vip.pop();
    int en;
    int ans = 1;
    while(!vip.empty()) {
        en = vip.front();
        vip.pop();

        int gap = en - st - 1;
        ans *= table[gap];

        std::swap(st, en);
    }

    std::cout << ans;
}