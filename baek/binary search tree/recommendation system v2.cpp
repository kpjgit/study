//21944
#include <bits/stdc++.h>

int N, M, P, L, G;
std::pair<int, int> pro[100001]; //난이도, 알고리즘
std::set<int> lev[101];
std::set<std::pair<int, int>> alg[101]; //난이도, 번호, 난이도->번호 순으로 정렬됨

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) {
        std::cin >> P >> L >> G;
        pro[P] = {L, G};
        lev[L].insert(P);
        alg[G].insert({L, P});
    }

    std::cin >> M;
    std::string op;
    for(int i = 0; i < M; i++) {
        std::cin >> op;
        if(op == "recommend") {
            std::cin >> G >> P;
            if(P == 1) {
                std::cout << (*std::prev(alg[G].end())).second << '\n';
            } else {
                std::cout << (*alg[G].begin()).second << '\n';
            }
        } else if(op == "recommend2") {
            std::cin >> P;
            if(P == 1) {
                for(int i = 100; i >= 0; i--) {
                    if(lev[i].empty()) continue;

                    std::cout << *std::prev(lev[i].end()) << '\n';
                    break;
                }
            } else {
                for(int i = 0; i <= 100; i++) {
                    if(lev[i].empty()) continue;

                    std::cout << *lev[i].begin() << '\n';
                    break;
                }
            }
        } else if(op == "recommend3") {
            std::cin >> P >> L;
            bool none = true;
            if(P == 1) {
                for(int i = L; i <= 100; i++) {
                    if(lev[i].empty()) continue;

                    std::cout << *lev[i].begin() << '\n';
                    none = false;
                    break;
                }
            } else {
                for(int i = L - 1; i >= 0; i--) {
                    if(lev[i].empty()) continue;

                    std::cout << *(std::prev(lev[i].end())) << '\n';
                    none = false;
                    break;
                }
            }

            if(none) std::cout << -1 << '\n';
        } else if(op == "add") {
            std::cin >> P >> L >> G;
            pro[P] = {L, G};
            lev[L].insert(P);
            alg[G].insert({L, P});
        } else { //solved
            std::cin >> P;
            lev[pro[P].first].erase(P);
            alg[pro[P].second].erase({pro[P].first, P});
        }
    }
}