#include <bits/stdc++.h>

std::string s;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> s;
    
    int ans = 0;
    int temp = 0;
    int sign = 1;
    for(char c : s) {
        if(c == '+' || c == '-') {
            ans += sign * temp;
            if(c == '-') sign = -1; //음수가 나온 이후로는 모두 음수로 더할 수 있다
            temp = 0;
        } else temp = temp * 10 + (c - '0');
    }
    ans += sign * temp;

    std::cout << ans;
}