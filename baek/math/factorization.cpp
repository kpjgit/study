//11653
#include <bits/stdc++.h>

int n;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;

    int temp = n;
    for(int i = 2; i * i <= n; i++) {
        while(temp % i == 0) {
            std::cout << i << '\n';
            temp /= i;
        }
    }

    if(temp != 1) std::cout << temp;
}