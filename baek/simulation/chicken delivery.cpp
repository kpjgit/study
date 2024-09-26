//15686
#include <bits/stdc++.h>

int N, M;

std::vector<std::pair<int, int>> chicken;
std::vector<std::pair<int, int>> house;

int main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int input;
    std::cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> input;
            if(input == 1) house.push_back({i, j});
            if(input == 2) chicken.push_back({i, j});
        }
    }

    std::vector<bool> brute(chicken.size(), true);
    std::fill(brute.begin(), brute.begin() + chicken.size() - M, false); //ture는 폐업
    
    int ans = 10000;
    do {
        int dist = 0;
        for(std::pair<int, int> h : house) {
            int temp = 100;

            for(int i = 0; i < chicken.size(); i++) {
                if(brute[i] == false) continue;
                temp = std::min(temp, std::abs(chicken[i].first - h.first) + std::abs(chicken[i].second - h.second));
            }
            dist += temp;
        }
        ans = std::min(ans, dist);
    } while(std::next_permutation(brute.begin(), brute.end()));

    std::cout << ans;
}