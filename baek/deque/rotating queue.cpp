//1021
#include <bits/stdc++.h>

int N, M;
std::deque<int> d;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;
    for(int i = 1; i <= N; i++) d.push_back(i);

    int ans = 0;
    int val;
    for(int i = 0; i < M; i++) {
        std::cin >> val;
        int loc = std::find(d.begin(), d.end(), val) - d.begin();

        while(d.front() != val) {
            if(loc < d.size() - loc) {
                d.push_back(d.front());
                d.pop_front();
            } else {
                d.push_front(d.back());
                d.pop_back();
            }
            ans++;
        }

        d.pop_front();
    }
    std::cout << ans;
}