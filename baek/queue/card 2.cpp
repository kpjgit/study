//2164
#include <bits/stdc++.h>

int N;
std::queue<int> q;

int main(void) {
    std::ios::sync_with_stdio(false);\
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 1; i <= N; i++) q.push(i);

    while(q.size() != 1) {
        q.pop();
        q.push(q.front());
        q.pop();
    }

    std::cout << q.front();
} 