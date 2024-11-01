//17219
#include <bits/stdc++.h>

int N, M;
std::unordered_map<std::string, std::string> um;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;
    std::string site, password;
    for(int i = 0; i < N; i++) {
        std::cin >> site >> password;
        um[site] = password;
    }

    for(int i = 0; i < M; i++) {
        std::cin >> site;
        std::cout << um[site] << '\n';
    }
}