#include <bits/stdc++.h>

int N;
long long C;

std::pair<int, long long> arr[20]; //가치, 갯수

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> N >> C;
    for (int i = 0; i < N; ++i) std::cin >> arr[i].first >> arr[i].second;

    std::sort(arr, arr + N, std::greater<std::pair<int, long long>>());

    long long ans = 0;
    long long cur[20]; //현재 루프에서 사용할 동전
    while(true) {
        long long pay = C;
        std::fill(cur, cur + N, 0);

        //C를 정확히 지급 가능한지 확인, 각 화폐는 배수이므로 가능한 가장 큰 것을 사용하는 것이 항상 유리하다
        for (int i = 0; i < N; i++) {
            if (arr[i].first > pay) continue; //큰 동전은 나중에 초과 지급을 위해 남겨둔다
            long long cost = std::min(arr[i].second, pay / arr[i].first);
            cur[i] = cost;
            pay -= cost * arr[i].first;
        }

        //가장 작은 동전으로 초과 지급 가능한지 확인
        if (pay > 0) {
            bool overpay = false;
            for (int i = N - 1; i >= 0; i--) {
                if (arr[i].second > cur[i]) { //pay는 arr[i].second - cur[i] > 0일 경우 항상 arr[i].first보다 작을 수 밖에 없다
                    cur[i]++;
                    overpay = true;
                    break;
                }
            }
            
            if (!overpay) break;
        }

        for (int i = 0; i < N; i++) {
            arr[i].second -= cur[i];
        }

        ans++;
    }

    std::cout << ans;
}