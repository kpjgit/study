//1292
#include <bits/stdc++.h>

int A, B;

int func(int n) {
    int i;
    int sum = 0;
    
    for(i = 1; i < n; i++) {
        sum += i * i;
        n -= i;
    }

    return sum + i * n;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> A >> B;
    int sumA = func(A - 1); //A도 포함해야함
    int sumB = func(B);
    
    std::cout << sumB - sumA;
}