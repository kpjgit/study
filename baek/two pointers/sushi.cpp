//2531
#include <bits/stdc++.h>

int N, d, k, c;
int arr[30000];

int used[3001];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> d >> k >> c;
    for(int i = 0; i < N; i++) std::cin >> arr[i];

    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < N * 2; i++) {
        int cur = i % N;

        if(i >= k) { //k개 유지
            if(used[c] == 0) {
                used[c]++;
                cnt++;
                ans = std::max(ans, cnt);
            }

            used[arr[(i - k) % N]]--;
            if(used[arr[(i - k) % N]] == 0) cnt--;
        }

        if(used[arr[cur]] == 0) {
            cnt++;
            ans = std::max(ans, cnt);
        }
        used[arr[cur]]++;
    }
    
    std::cout << ans;
}