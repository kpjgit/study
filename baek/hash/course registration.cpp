//13414
#include <bits/stdc++.h>

int K, L;
std::unordered_map<std::string, int> um;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> K >> L;
    std::string id;
    for(int i = 0; i < L; i++) {
        std::cin >> id;
        um[id] = i;
    }

    std::vector<std::pair<std::string, int>> ans(um.begin(), um.end());
    std::sort(ans.begin(), ans.end(), [](auto& a, auto& b){return a.second < b.second;});

    int len = std::min(K, static_cast<int>(ans.size()));
    for(int i = 0; i < len; i++) std::cout << ans[i].first << '\n';
}