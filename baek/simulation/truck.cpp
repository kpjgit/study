//13335
#include <bits/stdc++.h>

int n, w, L;
std::queue<int> trucks;
std::deque<std::pair<int, int>> on_bridge; //트럭 무게, 남은 시간

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> w >> L;
    int input;
    for(int i = 0; i < n; i++) {
        std::cin >> input;
        trucks.push(input);
    }

    int ans = 0;
    int temp = 0;
    while(!trucks.empty() || !on_bridge.empty()) {
        for(int i = 0; i < on_bridge.size(); i++) {
            on_bridge[i].second--;
        }

        if(!on_bridge.empty() && on_bridge[0].second == 0) {
            temp -= on_bridge[0].first;
            on_bridge.pop_front();
        }

        if(!trucks.empty() && temp + trucks.front() <= L) {
            on_bridge.push_back({trucks.front(), w});
            temp += trucks.front();
            trucks.pop();
        }

        ans++;
    }

    std::cout << ans;
}