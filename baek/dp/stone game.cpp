//9655
#include <bits/stdc++.h>

int N;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;

    if(N % 2 == 0) std::cout << "CY";
    else std::cout << "SK";
}