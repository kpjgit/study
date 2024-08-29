//2493
#include <bits/stdc++.h>

int N;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    std::stack<std::pair<int, int>> tower;
    tower.push({1000000001, 0});
    
    int input;
    for(int i = 1; i <= N; i++) {
        std::cin >> input;

        while(tower.top().first < input) {
            tower.pop();
        }
        std::cout << tower.top().second << ' ';
        tower.push({input, i});
    }
}