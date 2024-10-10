//1003
#include <bits/stdc++.h>

int T;

int zero[41];
int one[41];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> T;
    zero[0] = 1;
    zero[1] = 0;
    one[0] = 0;
    one[1] = 1;

    for(int i = 2; i < 41; i++) {
        zero[i] = zero[i - 1] + zero[i - 2];
        one[i] = one[i - 1] + one[i - 2];
    }

    int input;
    for(int i = 0; i < T; i++) {
        std::cin >> input;
        std::cout << zero[input] << ' ' << one[input] << '\n';
    }
}