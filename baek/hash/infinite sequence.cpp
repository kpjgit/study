//1351
#include <bits/stdc++.h>

long long N; 
int P, Q;
std::unordered_map<long long, long long> um; //N, A[N]

long long func(long long n) {
    if(n == 0) return 1;
    if(um[n]) return um[n]; //계산된 값이 있을 경우

    um[n] = func(n / P) + func(n / Q);
    return um[n];
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> P >> Q;
    std::cout << func(N);
}