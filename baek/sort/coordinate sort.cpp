//11650
#include<bits/stdc++.h>

int N;

std::vector<std::pair<int, int>> v;

bool cmp(const std::pair<int, int >& a, const std::pair<int, int>& b) {
    if(a.first < b.first) return true;
    if(a.first == b.first) return a.second < b.second;
    return false;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    int x, y;
    for(int i = 0; i < N; i++) {
        std::cin >> x >> y;
        v.push_back({x, y});
    }
    std::sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < N; i++) std::cout << v[i].first << ' ' << v[i].second << '\n';
}