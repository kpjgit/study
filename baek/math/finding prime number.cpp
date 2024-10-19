//1978
#include <bits/stdc++.h>

int N;

bool func(int a) {
    if(a == 1) return false;

    for(int i = 2; i * i <= a; i++) {
        if(a % i == 0) return false;
    }

    return true;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int ans = 0;
    std::cin >> N;
    for(int i = 0; i < N; i++) {
        int temp;
        std::cin >> temp;

        if(func(temp)) ans++;
    }

    std::cout << ans;
}