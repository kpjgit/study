//11652
#include <bits/stdc++.h>

int n;
long long cards[100005];

int main(void) {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 0; i < n; i++) std::cin >> cards[i];

    std::sort(cards, cards + n);

    long long ans = cards[0];
    int cnt = 0;
    int temp = 1;

    for(int i = 1; i < n; i++) {
        if(cards[i - 1] == cards[i]) temp++;
        else {
            if(temp > cnt) {
                cnt = temp;
                ans = cards[i - 1];
            }
            temp = 1;
        }
    }
    if(temp > cnt) ans = cards[n - 1];

    std::cout << ans;
}