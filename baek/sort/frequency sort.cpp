//2910
#include <bits/stdc++.h>

int N, C;
std::vector<std::pair<int, int>> v; //수, 빈도

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> C;
    for(int i = 0; i < N; i++) {
        int input;
        std::cin >> input;

        bool check = false;
        for(auto& p : v) {
            if(p.first == input) {
                p.second++;
                check = true;
                break;
            }
        }

        if(check == false) v.push_back({input, 1});
    }

    std::stable_sort(v.begin(), v.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {return a.second > b.second;});
    for(auto &p : v) {
        for(int i = 0; i < p.second; i++) std::cout << p.first << ' ';
    }
}