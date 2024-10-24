//1790
#include <bits/stdc++.h>

int N, k; //k=21 123456789/10111213141(5)1617181920, 21-9=12

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> k;

    int digit = 1;
    int exp = 1;
    while(k > 9LL * digit * exp) { //1~9: 9, 10~99: 180
        k -= 9 * digit * exp;
        exp *= 10;
        digit++;
    } //k에서 exp 미만의 자리수의 개수를 모두 빼고 나면 (k-1)/digit은 해당 자리수에서 몇번째 숫자인지 나타낸다, 10, 100 ...에서 시작하므로 -1 해줘야함

    int ans = exp + (k - 1) / digit;
    if(ans > N) std::cout << -1;
    else {
        std::string s = std::to_string(ans);
        std::cout << s[(k - 1) % digit];
    }
}