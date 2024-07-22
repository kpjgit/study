//7662
#include <bits/stdc++.h>

int t, k;
std::multiset<int> Q;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> t;
    for(int i = 0; i < t; i++) {
        std::cin >> k;
        for(int j = 0; j < k; j++) {
            std::string input;
            int val;
            std::cin >> input >> val;
            if(input == "I") {
                Q.insert(val);
            } else { //D
                if(val == 1) {
                    if(Q.size() != 0) Q.erase(--Q.end());
                } else { //-1
                    if(Q.size() != 0) Q.erase(Q.begin());
                }
            }
            
        }

        if(Q.size() == 0) std::cout << "EMPTY\n";
        else std::cout << *(--Q.end()) << ' ' << *Q.begin() << '\n';
    }
}