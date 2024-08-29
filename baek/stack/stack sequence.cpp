//1874
#include <bits/stdc++.h>

int n;
std::stack<int> s;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    int input;
    int count = 1;
    std::string ans;
    for(int i = 0; i < n; i++) {
        std::cin >> input;
        while(count <= input) {
            s.push(count++);
            ans += "+\n";
        }

        if(s.top() != input) {
            std::cout << "NO";
            return 0;
        }

        s.pop();
        ans += "-\n";
    }

    std::cout << ans;
}