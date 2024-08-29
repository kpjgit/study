//1158
#include <bits/stdc++.h>

int N, K;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> K;
    std::list<int> l;

    for(int i = 1; i <= N; i++) l.push_back(i);

    auto iter = l.begin();
    std::cout << '<';
    while(!l.empty()) {
        for(int i = 0; i < K - 1; i++) {
            iter++;
            if(iter == l.end()) iter = l.begin();
        }

        if(l.size() != 1) {
            std::cout << *iter << ", ";
        } else {
            std::cout << *iter;
        }

        iter = l.erase(iter);
        if(iter == l.end()) iter = l.begin(); //끝 원소를 삭제했을 때
    }
    std::cout << '>';
}