//10799
#include <bits/stdc++.h>

std::string input;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> input;
    long long ans = 0;
    int cnt = 0;
    for(int i = 0; i < input.size(); i++) {
        if(input[i] == '(') cnt++;

        if(input[i] == ')') {
            if(input[i - 1] == '(') ans += --cnt;
            else {
                cnt--;
                ans++;
            }
        }
    }

    std::cout << ans;
}