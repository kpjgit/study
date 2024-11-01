//9375
#include <bits/stdc++.h>

int test;
int n;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> test;
    std::string s;
    for(int num = 0; num < test; num++) {
        std::unordered_map<std::string, int> um;
        std::cin >> n;
        int ans = 1;
        for(int i = 0; i < n; i++) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
            std::cin >> s;
            um[s]++;
        }

        for(const std::pair<std::string, int>& i : um) {
            ans *= i.second + 1;
        }
        std::cout << ans - 1 << '\n';
    }
}