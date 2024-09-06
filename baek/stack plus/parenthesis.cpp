//9012
#include <bits/stdc++.h>

int T;
std::string input;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> T;
    for(int i = 0; i < T; i++) {
        std::cin >> input;
        std::stack<char> st;

        for(char c : input) {
            if(st.empty()) {
                st.push(c);
            } else if(st.top() == '(' && c == ')') {
                st.pop();
            } else st.push(c);
        }

        if(st.empty()) std::cout << "YES\n";
        else std::cout << "NO\n";
    }

}