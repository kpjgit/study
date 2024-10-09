//11652
#include <bits/stdc++.h>

int N;
long long cards[100000]; //최대 입력이 100000이니 std::unordered_map<long long, int>으로 대체 가능

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) std::cin >> cards[i];
    std::sort(cards, cards + N);

    int cnt = 0;
    int temp = 1;
    long long ans = cards[0];
    for(int i = 1; i < N; i++) {
        if(cards[i - 1] == cards[i]) temp++;
        else {
            if(temp > cnt) {
                cnt = temp;
                ans = cards[i - 1];
            }
            temp = 1;
        }
    }
    if(temp > cnt) ans = cards[N - 1];

    std::cout << ans;
}