//14003
#include <bits/stdc++.h>

int N;
int arr[1'000'000];

int cnt = 0;
int table[1'000'000];
int path[1'000'000];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) std::cin >> arr[i];

    table[cnt] = arr[0];
    cnt++;

    for(int i = 1; i < N; i++) {
        if(table[cnt - 1] < arr[i]) {
            table[cnt] = arr[i];
            path[i] = cnt; //현재 cnt를 기록해뒀다 경로를 복원하는데 사용한다
            cnt++;
        } else {
            int* loc = std::lower_bound(table, table + cnt, arr[i]);
            *loc = arr[i];
            path[i] = loc - table;
        }
    }

    std::cout << cnt << '\n';

    std::vector<int> ans;
    for(int i = N - 1; i >= 0; i--) {
        if(path[i] == cnt - 1) {
            ans.push_back(arr[i]);
            cnt--;
        }
    }

    for(auto i = ans.rbegin(); i != ans.rend(); i++) std::cout << *i << ' ';
}