//4949
#include <bits/stdc++.h>

std::string input;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while(true) {
        std::getline(std::cin, input);
        if(input == ".") break;

        std::stack<char> stack;
        for(char i : input) {
            if(i == '(' || i == '[') stack.push(i);

            if(i == ')') {
                if(stack.empty()) {
                    stack.push(i);
                    break;
                }

                if(stack.top() == '(') stack.pop();
                else break;
            }

            if(i == ']') {
                if(stack.empty()) {
                    stack.push(i);
                    break;
                }

                if(stack.top() == '[') stack.pop();
                else break;
            }
        }

        if(stack.empty()) std::cout << "yes\n";
        else std::cout << "no\n";
    }
}