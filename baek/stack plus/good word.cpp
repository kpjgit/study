//3986
#include <bits/stdc++.h>

int N;
std::string input;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int ans = 0;
    std::cin >> N;
    for(int i = 0; i < N; i++) {
        std::cin >> input;
        std::stack<char> st;
        for(char i : input) {
            if(st.empty()) {
                st.push(i);
            } else if(st.top() == i) {
                st.pop();
            } else st.push(i);
        }

        if(st.empty()) ans++;
    }

    std::cout << ans;
}