//1181
#include <bits/stdc++.h>

int N;
std::vector<std::string> v;

bool cmp(const std::string& a, const std::string& b) {
    if(a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> N;
    for(int i = 0; i < N; i++) {
        std::cin >> s;
        v.push_back(s);
    }

    std::sort(v.begin(), v.end(), cmp);
    v.erase((std::unique(v.begin(), v.end())), v.end());
    for(auto& s : v) std::cout << s << '\n';
}