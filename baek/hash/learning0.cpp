//-1
#include <bits/stdc++.h>
//load factor <= 1 chaining, <= 0.75 open addressing
const int M = 1000003;
const int a = 1000;

int my_hash(int x) {
    return (M + x % M) % M;
}

int my_hash(const std::string& s) {
    int h = 0;
    for(auto x : s) {
        h = (h * a + x) % M;
    }

    return h;
} 

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
}