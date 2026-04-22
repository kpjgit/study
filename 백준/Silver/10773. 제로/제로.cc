#include <iostream>
#include <stack>

int K;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> K;
    std::stack<int> s;
    int op;
    for(int i = 0; i < K; i++) {
        std::cin >> op;
        if(op == 0) {
            if(!s.empty()) s.pop();
        } else {
            s.push(op);
        }
    }
    
    long long ans = 0;
    while(!s.empty()) {
        ans += s.top();
        s.pop();
    }
    
    std::cout << ans;
}