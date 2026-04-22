#include <iostream>

long long S;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> S;
    long long num = 1;
    long long ans = 0;
    while(S >= num) {
        S -= num;
        num++;
        ans++;
    }
    
    std::cout << ans;
}