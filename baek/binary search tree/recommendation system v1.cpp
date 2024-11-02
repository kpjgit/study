//21939
#include <bits/stdc++.h>

int N, M;
int pro[100001];
std::set<int> lev[101];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    int P, L;
    for(int i = 0; i < N; i++) {
        std::cin >> P >> L;
        pro[P] = L;
        lev[L].insert(P);
    }

    std::cin >> M;
    std::string op;
    for(int i = 0; i < M; i++) {
        std::cin >> op >> P;
        if(op == "add") {
            std::cin >> L;
            pro[P] = L;
            lev[L].insert(P);
        } else if(op == "recommend") {
            if(P == 1) {
                for(int i = 100; i >= 0; i--) {
                    if(lev[i].empty()) continue;

                    std::cout << *std::prev(lev[i].end()) << '\n';
                    break;
                }
            } else {
                for(int i = 0; i <= 100; i++) {
                    if(lev[i].empty()) continue;

                    std::cout << *(lev[i].begin()) << '\n';
                    break;
                }
            }
        } else { //solved
            lev[pro[P]].erase(P);
        }
    }
}