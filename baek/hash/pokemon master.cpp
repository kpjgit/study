//1620
#include <bits/stdc++.h>

int n, m;
std::unordered_map<std::string, int> dic;
std::string names[100001];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        std::cin >> names[i];
        dic[names[i]] = i;
    }

    for(int i = 0; i < m; i++) {
        std::string input;
        std::cin >> input;
        if(std::isdigit(input[0])) {
            std::cout << names[std::stoi(input)] << '\n';
        } else {
            std::cout << dic[input] << '\n';
        }
    }
}