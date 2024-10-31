//7785
#include <bits/stdc++.h>

int n;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    std::unordered_set<std::string> employee;
    std::string name, input;
    for(int i = 0; i < n; i++) {
        std::cin >> name >> input;
        if(input == "enter") employee.insert(name);
        else employee.erase(name);
    }

    std::vector<std::string> v(employee.begin(), employee.end());
    std::sort(v.begin(), v.end(), std::greater<std::string>());
    for(auto& s : v) std::cout << s << '\n';
}