//1202
#include <bits/stdc++.h>

int N, K;
std::pair<int, int> jewel[300000]; //값, 무게
std::multiset<int> bag; //보석의 무게가 어떻든 가방 하나에는 하나의 보석만 들어가므로 
                        //가장 비싼 보석을 가능한 가장 작은 가방에 넣는 것이 이득

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> K;
    for(int i = 0; i < N; i++) std::cin >> jewel[i].second >> jewel[i].first;
    std::sort(jewel, jewel + N, std::greater<std::pair<int, int>>());

    int temp;
    for(int i = 0; i < K; i++) {
        std::cin >> temp;
        bag.insert(temp);
    }
    
    long long ans = 0;
    for(int i = 0; i < N; i++) {
        int M, V;
        std::tie(V, M) = jewel[i];

        if(bag.empty()) break;

        auto iter = bag.lower_bound(M);
        if(iter == bag.end()) continue; //해당하는 가방 없음
        ans += V;
        bag.erase(iter);
    }

    std::cout << ans;
}