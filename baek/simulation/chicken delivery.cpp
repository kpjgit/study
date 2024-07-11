//15686
#include <bits/stdc++.h>

int n, m;
int city[51][51];

std::vector<std::pair<int, int>> chicken;
std::vector<std::pair<int, int>> house;


int main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            std::cin >> city[i][j];
            if(city[i][j] == 1) house.push_back({i, j});
            if(city[i][j] == 2) chicken.push_back({i, j});
        }
    }

    std::vector<int> brute(chicken.size(), 1);
    std::fill(brute.begin(), brute.begin() + chicken.size() - m, 0);
    int ans = 300000;

    do {
        int dist = 0;
        for(auto h: house) {
            int temp = 300000;
            for(int i = 0; i < chicken.size(); i++) {
                if(brute[i] == 0) continue;
                temp = std::min(temp, std::abs(chicken[i].first - h.first) + std::abs(chicken[i].second - h.second));
            }
            dist += temp;
        }
        ans = std::min(ans, dist);
    } while(std::next_permutation(brute.begin(), brute.end()));
    std::cout << ans << '\n';
}