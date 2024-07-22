//1202
#include <bits/stdc++.h>

int n, k;
std::pair<int, int> jewels[300001];
std::multiset<int> bags;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> k;
    for(int i = 0; i < n; i++) {
        std::cin >> jewels[i].second >> jewels[i].first;
    }
    std::sort(jewels, jewels + n);

    for(int i = 0; i < k; i++) {
        int temp;
        std::cin >> temp;
        bags.insert(temp);
    }

    long long ans = 0;

    for(int i = n - 1; i >= 0; i--) {
        int w, v;
        w = jewels[i].second;
        v = jewels[i].first;
        //std::tie(v, w) = jewels[i];

        //std::multiset<int>::iterator iter = bags.lower_bound(w);
        auto iter = bags.lower_bound(w);
        if(iter == bags.end()) continue;
        bags.erase(iter);
        ans += v;
    }

    std::cout << ans;
}