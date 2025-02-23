//15311
#include <bits/stdc++.h>

int N;
//1000000=1000*1000
//약봉지의 최대 숫자는 2000이므로 약이 1000개 들은 약봉지가 1000개, 1개 들은 약봉지가 1000개
//1000 이하의 숫자는 1000개의 1의 조합으로 만들 수 있다

int main(void) {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    
    std::cin >> N;
    std::cout << 1000 + (N / 1000) << '\n';
    for(int i = 0; i < 1000; i++) std::cout << "1 ";
    for(int i = 0; i < N / 1000; i++) std::cout << "1000 ";
}