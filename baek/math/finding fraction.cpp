//1193
#include <bits/stdc++.h>

int X; //1/1  1/2 2/1  1/3 2/2 3/1

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> X;
    int row = 1;
    int sum = 1;
    if(X == 1) {
        std::cout << "1/1";
        return 0;
    }
    for(int i = 2; ; i++) {
        int temp;
        if(i % 2 == 0) temp = i / 2 * (i + 1);
        else temp = temp = (i + 1) / 2 * i;

        if(temp >= X) break;
        else {
            row = i;
            sum = temp;
        }
    }

    int order = X - sum;

    if(row % 2 == 0) std::cout << row + 2 - order << '/' << order;
    else std::cout << order << '/' << row + 2 - order;
}