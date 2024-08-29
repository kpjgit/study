//17298
#include <bits/stdc++.h>

int N;
int temp[1000000];
int ans[1000000];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    std::stack<int> s;
    int input;
    for(int i = 0; i < N; i++) std::cin >> temp[i];

    for(int i = N - 1; i >= 0; i--) {
        while(!s.empty() && s.top() <= temp[i]) s.pop();

        if(s.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = s.top();
        }

        s.push(temp[i]);
    }

    for(int i = 0; i < N; i++) std::cout << ans[i] << " ";
}