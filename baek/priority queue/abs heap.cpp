//11286
#include <bits/stdc++.h>

int n;


class cmp {
public:
    bool operator() (int a, int b) {
        if(a * a != b * b) return a * a > b * b; //std::abs(a)
        return a > 0 && b < 0;
    }
};

std::priority_queue<int, std::vector<int>, cmp> q;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    for(int i = 0; i < n; i++) {
        int input;
        std::cin >> input;
        if(input == 0) {
            if(q.empty()) {
                std::cout << 0 << '\n';
            } else {
                std::cout << q.top() << '\n';
                q.pop();
            }
        } else {
            q.push(input);
        }
    }
}