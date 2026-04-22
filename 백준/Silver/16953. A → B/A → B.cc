#include <iostream>

int A, B;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> A >> B;    
    
    int cnt = 0;
    while(B > A) {
        if(B % 10 == 1) {
            B /= 10;
            cnt++;
        } else if(B % 2 == 0) {
            B /= 2;
            cnt++;
        } else {
            std::cout << -1;
            return 0;
        }
    }
    
    if(B == A) std::cout << cnt + 1;
    else std::cout << -1;
}