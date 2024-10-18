//2457
#include <bits/stdc++.h>

int N;
std::pair<int, int> arr[100000];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    int sm, sd, em, ed;
    for(int i = 0; i < N; i++) {
        std::cin >> sm >> sd >> em >> ed;
        arr[i].first = sm * 100 + sd;
        arr[i].second = em * 100 + ed;
    }
    std::sort(arr, arr + N);

    int st = 301;
    int en = 301;
    int ans = 0;
    bool carry = false;
    for(int i = 0; i < N; i++) {
        if(arr[i].second <= st) continue; //3월 1일 이전의 값은 필요 없음
        if(en >= 1201) break;

        if(arr[i].first <= st) {
            en = std::max(en, arr[i].second);
            carry = true;
        } else if(carry == true && arr[i].first > st) {
            st = en;
            ans++;
            i--;
            carry = false;
        } else break;
    }
    
    if(carry == true) ans++;
    if(en < 1201) ans = 0;

    std::cout << ans;
}