#include <iostream>

int N;

bool func(int num) {
    int cnt = 0;
    while(num > 0) {
        if(num % 10 == 6) cnt++;
        else cnt = 0;
        num /= 10;
        if(cnt == 3) return true;
    }
    return false;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> N;
    int cnt = 0;
    int num = 0;
    while(cnt < N) {
        num++;
        if(func(num)) cnt++;
    }
    
    std::cout << num;
}