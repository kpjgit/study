//7662
#include <bits/stdc++.h>

int T, k;
std::multiset<int> Q;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> T;
    char op;
    int val;
    for(int num = 0; num < T; num++) {
        std::cin >> k;
        for(int i = 0; i < k; i++) {
            std::cin >> op >> val;
            if(op == 'I') Q.insert(val);
            else {
                if(Q.empty()) continue;

                if(val == 1) Q.erase(std::prev(Q.end())); //Q.erase(--Q.end())
                else Q.erase(Q.begin());
            }
        }

        if(Q.empty()) std::cout << "EMPTY\n";
        else std::cout << *std::prev(Q.end()) << ' ' << *Q.begin() << '\n';
        Q.clear();
    }
}