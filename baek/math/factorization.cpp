//11653
#include <bits/stdc++.h>

int N;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    std::vector<int> primes;
    int i = 2;
    while(i * i <= N) {
        if(N % i == 0) {
            N /= i;
            primes.push_back(i);
        } else i++;
    }
    if(N > 1) primes.push_back(N);

    for(int i : primes) std::cout << i << '\n';
}