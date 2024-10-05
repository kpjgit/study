//14888
#include <bits/stdc++.h>

int N;
int arr[100];
int oper[4];

int max = -1000000000;
int min = 1000000000;

void func(int cnt, int temp) {
    if(cnt == N - 1) {
        max = std::max(max, temp);
        min = std::min(min, temp);
        return;
    }

    for(int i = 0; i < 4; i++) {
        if(oper[i] == 0) continue;

        oper[i]--;
        if(i == 0) {
            func(cnt + 1, temp + arr[cnt + 1]);
        } else if(i == 1) {
            func(cnt + 1, temp - arr[cnt + 1]);
        } else if(i == 2) {
            func(cnt + 1, temp * arr[cnt + 1]);
        } else {
            func(cnt + 1, temp / arr[cnt + 1]);
        }
        oper[i]++;
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) std::cin >> arr[i];
    for(int i = 0; i < 4; i++) std::cin >> oper[i];

    func(0, arr[0]);
    std::cout << max << '\n' << min;
}