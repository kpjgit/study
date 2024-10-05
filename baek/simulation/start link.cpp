//14889
#include <bits/stdc++.h>

int N;
int arr[20][20];

bool used[20];

int ans = 20 * 20 * 100;

void func(int cnt, int prev) {
    if(cnt == N / 2) {
        int start = 0;
        int link = 0;

        for(int i = 0; i < N; i++) {
            for(int j = i + 1; j < N; j++) {
                if(used[i] == true && used[j] == true) start += arr[i][j] + arr[j][i];
                else if(used[i] == false && used[j] == false) link += arr[i][j] + arr[j][i]; 
            }
        }

        ans = std::min(ans, std::abs(start - link));
        return;
    }

    for(int i = prev; i < N; i++) {
        if(used[i] == true) continue;

        used[i] = true;
        func(cnt + 1, i + 1);
        used[i] = false;
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) std::cin >> arr[i][j];
    }

    func(0, 0);
    std::cout << ans;
}