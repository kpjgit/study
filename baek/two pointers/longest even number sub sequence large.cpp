//22862
#include <bits/stdc++.h>

int N, K; 
int S[1000000];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> K;
    for(int i = 0; i < N; i++) std::cin >> S[i];

    int st = 0;
    int en = 0;
    int cnt = 0;
    int ans = 0;
    while(st < N && en < N) {
        if(S[en] % 2 == 1) cnt++;

        while(cnt > K) {
            if(S[st] % 2 == 1) cnt--;
            st++;
        }

        ans = std::max(ans, en - st + 1 - cnt);
        en++;
    }
    
    std::cout << ans;
}