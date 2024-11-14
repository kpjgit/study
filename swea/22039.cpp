#include <bits/stdc++.h>

int T, N; //100번째 피보나치 수는 너무 커서 long long으로 저장 불가

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> T;
    for(int num = 0; num < T; num++) {
        std::cin >> N;

        if(N % 3 == 0) { //fibo(n)=fibo(n-1)+fibo(n-2)이므로 3개 단위로 분배 가능
            for(int i = 0; i < N / 3; i++) std::cout << "BBA";
        } else if(N % 3 == 1) { //뒤에 1이 남으므로 분배 불가
            std::cout << "impossible";
        } else { //뒤에 2가 남으면 fibo[1], fibo[2]로 분배가 가능
            std::cout << "BA";
            for(int i = 0; i < N / 3; i++) std::cout << "BBA";
        }
        std::cout << '\n';
    }
}