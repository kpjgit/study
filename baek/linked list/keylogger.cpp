//5397
#include <bits/stdc++.h>

std::string s;
int N;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) {
        std::cin >> s;
        std::list<char> l;

        auto iter = l.begin();
        for(char i : s) {
            if(i == '<') {
                if(iter != l.begin()) iter--;
            } else if(i == '>') {
                if(iter != l.end()) iter++;
            } else if(i == '-') {
                if(iter != l.begin()) {
                    iter--;
                    iter = l.erase(iter);
                }
            } else {
                l.insert(iter, i);
            }
        }

        for(auto i : l) std::cout << i;
        std::cout << '\n';
    }
}