//7785
#include <bits/stdc++.h>

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::unordered_set<std::string> s;

    for(int i = 0; i < n; i++) {
        std::string name;
        std::string input;
        std::cin >> name >> input;
        if(input == "enter") {
            s.insert(name);
        } else {
            s.erase(name);
        }
    }

    std::vector<std::string> ans(s.begin(), s.end());
    std::sort(ans.begin(), ans.end(), std::greater<std::string>());
    for(auto i : ans) std::cout << i << '\n';
}