//2504
#include <bits/stdc++.h>

std::string input;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> input;
    std::stack<char> st;
    int ans = 0;
    int temp = 1;
    for(int i = 0; i < input.size(); i++) {
        if(input[i] == '(') {
            temp *= 2;
            st.push(input[i]);
        }

        if(input[i] == '[') {
            temp *= 3;
            st.push(input[i]);
        }

        if(input[i] == ')') {
            if(st.empty() || st.top() != '(') {
                std::cout << 0;
                return 0;
            }

            if(input[i - 1] == '(') ans += temp;
            st.pop();
            temp /= 2;
        }

        if(input[i] == ']') {
            if(st.empty() || st.top() != '[') {
                std::cout << 0;
                return 0;
            }

            if(input[i - 1] == '[') ans += temp;
            st.pop();
            temp /= 3;
        }
    }


    if(st.empty()) std::cout << ans;
    else std::cout << 0;
}