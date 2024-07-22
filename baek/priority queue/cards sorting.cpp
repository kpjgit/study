//1715
#include <bits/stdc++.h>

int n;
std::priority_queue<int, std::vector<int>, std::greater<int>> q;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    for(int i = 0; i < n; i++) {
        int input;
        std::cin >> input;
        q.push(input);
    }

    int ans = 0;
    while(q.size() > 1) {
        int temp = 0;
        temp += q.top();
        q.pop();
        temp += q.top();
        q.pop();
        q.push(temp);
        ans += temp;
    }

    std::cout << ans;
}