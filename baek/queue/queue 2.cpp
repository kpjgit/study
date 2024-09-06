//18258
#include <bits/stdc++.h>

int N;
int qu[2000001];
int size, counter, front;

int main(void) {
    std::ios::sync_with_stdio(false);\
    std::cin.tie(nullptr);

    std::cin >> N;
    std::string input;

    for(int i = 0; i < N; i++) {
        std::cin >> input;
        if(input == "push") {
            int val;
            std::cin >> val;
            qu[counter++] = val;
            size++;
        } else if(input == "pop") {
            if(size <= 0) std::cout << -1 << '\n';
            else {
                std::cout << qu[front++] << '\n';
                size--;
            }
        } else if(input == "size") {
            std::cout << size << '\n';
        } else if(input == "empty") {
            if(size > 0) std::cout << 0 << '\n';
            else std::cout << 1 << '\n';
        } else if(input == "front") {
            if(size <= 0) std::cout << -1 << '\n';
            else {
                std::cout << qu[front] << '\n';
            }
        } else {
            if(size <= 0) std::cout << -1 << '\n';
            else {
                if(counter == 0) std::cout << qu[2000000] << '\n';
                else std::cout << qu[counter - 1] << '\n';
            }
        }

        if(counter > 2000000) counter = 0;
        if(front > 2000000) front = 0;
    }
} 