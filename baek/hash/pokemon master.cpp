//1620
#include <bits/stdc++.h>

int N, M;
std::string arr[100001];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;
    std::unordered_map<std::string, int> dic;
    std::string s;
    for(int i = 1; i <= N; i++) {
        std::cin >> s;
        dic[s] = i;
        arr[i] = s;
    }

    for(int i = 0; i < M; i++) {
        std::cin >> s;
        if(s[0] >= '0' && s[0] <= '9') std::cout << arr[std::stoi(s)] << '\n';
        else std::cout << dic[s] << '\n';
    }
}